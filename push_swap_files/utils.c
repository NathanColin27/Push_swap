/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:27:16 by nathan            #+#    #+#             */
/*   Updated: 2021/03/19 11:09:39 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int		exit_error(void)
{
	write(2, "Error\n", 7);
	//free_all()//
	exit(0);
}

void	reset_data(void)
{
	t_data *data;

	data = get_data();
	data->b_biggest = 0;
	data->b_rot = 0;
	data->b_rrot = 0;
	data->b_smallest = 0;
	data->big_flag = 0;
	data->small_flag = 0;
	data->s_rot = 0;
	data->s_rrot = 0;
}

int		find_smallest(t_stack *st)
{
	int		res;
	size_t	i;

	res = st->numbers[0];
	i = 1;
	while (i < st->len)
	{
		if (st->numbers[i] < res)
			res = st->numbers[i];
		i++;
	}
	return (res);
}

int		find_biggest(t_stack *st)
{
	int		res;
	size_t	i;

	res = st->numbers[0];
	i = 1;
	while (i < st->len)
	{
		if (st->numbers[i] > res)
			res = st->numbers[i];
		i++;
	}
	return (res);
}

void	find_big_small(t_stack *st)
{
	get_data()->b_biggest = find_biggest(st);
	get_data()->b_smallest = find_smallest(st);
}

int		is_sorted(t_stack *a)
{
	size_t i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->numbers[i] < a->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}
