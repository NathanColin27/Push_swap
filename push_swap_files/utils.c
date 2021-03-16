/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:27:16 by nathan            #+#    #+#             */
/*   Updated: 2021/03/16 19:25:49 by nathan           ###   ########.fr       */
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

int find_smallest(t_stack *st)
{
	int res;
	size_t i;
	
	
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

int find_biggest(t_stack *st)
{
	int res;
	size_t i;

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

int is_sorted(t_stack *a)
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