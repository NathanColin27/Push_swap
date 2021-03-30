/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:36:19 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 13:13:04 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"

int		find_chunks(t_stack *stack, int chunk_total, int chunk_num, int flag)
{
	int		*array;
	int		ret;
	size_t	i;
	int		index;

	i = 0;
	if (!(array = (int*)malloc(sizeof(int) * stack->len)))
		printf("malloc error");
	while (i < stack->len)
	{
		array[i] = stack->numbers[i];
		i++;
	}
	sort_array(array, stack->len);
	index = ((stack->len) / chunk_total) * (chunk_num - flag) - 1;
	if ((size_t)index >= stack->len)
		index = 0;
	ret = array[index];
	if (chunk_num == 1 && flag == 1)
		ret = array[0];
	if (chunk_num == chunk_total && flag == 0)
		ret = array[stack->len - 1];
	free(array);
	return (ret);
}

void	push_back(t_stack *a, t_stack *b)
{
	t_data	*d;
	int		tmp;

	d = get_data();
	if (d->s_rot > 0)
		while (d->s_rot-- > 0)
			inst_exec("rb", a, b);
	else if (d->s_rrot >= 0)
		while (d->s_rrot-- >= 0)
			inst_exec("rrb", a, b);
	else if (d->b_rot > 0)
		while (d->b_rot-- > 0)
			inst_exec("rb", a, b);
	else if (d->b_rrot >= 0)
		while (d->b_rrot-- >= 0)
			inst_exec("rrb", a, b);
	inst_exec("pa", a, b);
	tmp = d->small_flag;
	reset_data();
	find_big_small(b);
	find_move();
	if (tmp && d->s_rot)
		inst_exec("rr", a, b);
	else if (tmp)
		inst_exec("ra", a, b);
}

void reset_position()
{
	
}

void	push_chunks(t_stack *a, t_stack *b, int chunk_total, int chunk_num)
{
	size_t	count;
	int		chunk_top;
	int		chunk_bot; 

	count = 0;
	chunk_bot = find_chunks(a, chunk_total, chunk_num, 1);
	chunk_top = find_chunks(a, chunk_total, chunk_num, 0);
	get_data()->chunk_top = chunk_top;
	while (has_between_min_max(a, chunk_bot, chunk_top))
	{
		if (a->numbers[a->len - 1] < chunk_top && a->numbers[a->len - 1] >= chunk_bot)
			inst_exec("pb", a, b);
		else if (a->numbers[a->len - 1] >= chunk_bot && chunk_num == chunk_total)
			inst_exec("pb", a, b);
		else
			inst_exec("ra", a, b);
		count ++;
	}
	if (chunk_num > 1)
	{
		if (chunk_end_to_bot(a, chunk_bot) >= chunk_end_to_top(a, chunk_bot))
			while (a->numbers[0] != chunk_bot - 1)
				inst_exec("ra", a, b);
		else
			while (a->numbers[0] != chunk_bot - 1)
				inst_exec("rra", a, b);
	}
}

void	solve(t_stack *a, t_stack *b, int chunk_total, int chunk_num)
{
	while (a->len)
	{
		push_chunks(a,b, chunk_total, chunk_num);
		while (b->len)
		{
			find_big_small(b);
			find_move();
			push_back(a, b);
			reset_data();
		}
		if (chunk_num == chunk_total)
		{
			while (!is_sorted(a) && get_data()->inst_count < 1000)
				inst_exec("ra", a, b);
			break ;
		}
		chunk_num++;
	}
}
