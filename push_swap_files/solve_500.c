/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_500.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:36:19 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/24 12:41:44 by ncolin           ###   ########.fr       */
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
	while (count <= a->size - 1 && has_between_min_max(a, chunk_bot, chunk_top))
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
		}
		while (get_data()->rotate_left != 0)
		{
			inst_exec("ra", a, b);
			get_data()->rotate_left--;
		}
		if(chunk_num == chunk_total)
		{
			while (!is_sorted(a))
				inst_exec("ra", a, b);
			break ;
		}
		chunk_num++;
	}
}