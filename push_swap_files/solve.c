/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:36:19 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/24 18:26:07 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"

int	find_chunks(t_stack *stack, int chunk_total, int chunk_num, int flag)
{
	int *array;
	int ret;
	size_t i;
	
	i = 0;
	if (!(array = (int*)malloc(sizeof(int)*stack->len)))
		printf("malloc error");
	while (i < stack->len)
	{
		array[i] = stack->numbers[i];
		i++;
	}
	sort_array(array, stack->len);
	ret = array[((stack->len)/chunk_total) * (chunk_num - flag) - 1 ];
	if (chunk_num == 1 && flag == 1)
	{
		ret = array[0];
	}
	if (chunk_num == chunk_total && flag == 0)
	{
		ret = array[stack->len - 1];
	}
	free(array);
	return (ret);
}

int	chunk_end_to_top(t_stack *a, int min)
{
	int		i;

	i = 0;
	while (a->numbers[a->len - i - 1] != min - 1)
		i++;
	return (i);
}

int	chunk_end_to_bot(t_stack *a, int min)
{
	int		i;

	i = 0;
	while (a->numbers[i] != min - 1)
		i++;
	return (i);
}

void push_chunks(t_stack *a, t_stack *b, int chunk_total, int chunk_num)
{
	size_t count = 0;
	int chunk_top;
	int chunk_bot; 
	
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
	if(chunk_num > 1)
	{
		if (chunk_end_to_bot(a, chunk_bot) >= chunk_end_to_top(a, chunk_bot))
			while (a->numbers[0] != chunk_bot - 1)
				inst_exec("ra", a, b);
		else
			while (a->numbers[0] != chunk_bot - 1)
				inst_exec("rra", a, b);
	}
}

void	solve_3_inverted_b(t_stack *a, t_stack *b)
{
	int top;
	int mid;
	int bot;

	top = b->numbers[2];
	mid = b->numbers[1];
	bot = b->numbers[0];
	if (top > mid && mid < bot && top < bot)
		inst_exec("rrb", a, b);
	else if (top > mid && mid < bot && top > bot)
	{
		inst_exec("sb", a, b);
		inst_exec("rb", a, b);
	}
	else if (top < mid && bot > mid && bot > top)
	{
		inst_exec("sb", a, b);
		inst_exec("rrb", a, b);
	}
	else if (top < mid && mid > bot && top < bot)
		inst_exec("rb", a, b);
	else if (top < mid && mid > bot && top > bot)
		inst_exec("sb", a, b);
}

void solve(t_stack *a, t_stack *b, int chunk_total, int chunk_num)
{
	while(a->len)
	{
		push_chunks(a,b, chunk_total, chunk_num);
		while (b->len)
		{
			find_big_small(b);
			find_move();
			push_back(a, b);
			reset_data();
			// if (b->len == 3)
			// {
			// 	solve_3_inverted_b(a,b);
			// 	inst_exec("pa", a,b);
			// 	inst_exec("pa", a,b);
			// 	inst_exec("pa", a,b);
			// }
		}
		if(chunk_num == chunk_total)
		{
			while (!is_sorted(a) && get_data()->inst_count < 1000)
				inst_exec("ra", a, b);
			break ;
		}
		chunk_num++;
	}
}