/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:08:48 by nathan            #+#    #+#             */
/*   Updated: 2021/03/30 13:09:54 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int		solve_mute(t_stack *a, t_stack *b, int chunk_total, int chunk_num)
{
	get_data()->print_flag = 0;
	while (a->len)
	{
		push_chunks(a, b, chunk_total, chunk_num);
		while (b->len)
		{
			find_big_small(b);
			find_move();
			push_back(a, b);
			reset_data();
		}
		if (chunk_num == chunk_total)
		{
			while (!is_sorted(a))
				inst_exec("ra", a, b);
			break ;
		}
		chunk_num++;
	}
	return (get_data()->inst_count);
}

void	copy_array(int *dest_array, int *src_array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest_array[i] = src_array[i];
		i++;
	}
}

int		try_chunk_numbers(t_stack *a, t_stack *b, int chunk_total)
{
	int	min_inst_count;
	int	current_inst_count;
	int	result;
	int	*tmp;

	tmp = ft_calloc(a->size, sizeof(int));
	copy_array(tmp, a->numbers, a->size);
	min_inst_count = INT_MAX;
	while (chunk_total < 10)
	{
		init_data(get_data(), a, b);
		copy_array(a->numbers, tmp, a->size);
		current_inst_count = solve_mute(a, b, chunk_total, 1);
		if (current_inst_count < min_inst_count)
		{
			min_inst_count = current_inst_count;
			result = chunk_total;
		}
		chunk_total++;
	}
	copy_array(a->numbers, tmp, a->size);
	free(tmp);
	return (result);
}

int		process(t_stack *a, t_stack *b)
{
	int best_chunk_num;

	if (a->size <= 6)
		solve_up_to_6(a, b);
	else
	{
		best_chunk_num = try_chunk_numbers(a, b, 1);
		init_data(get_data(), a, b);
		solve(a, b, best_chunk_num, 1);
	}
	return (0);
}
