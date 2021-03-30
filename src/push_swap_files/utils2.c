/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:42:06 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 13:07:31 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"

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

void	sort_array(int *array, size_t len)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	tmp = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
