/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:35:59 by nathan            #+#    #+#             */
/*   Updated: 2021/03/24 10:45:15 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"


void	solve_100(t_stack *a, t_stack *b)
{
	int median;
	int flag;

	flag = 1;
	median = find_median(a);
	while (a->len)
	{
		push_median(a, b, median, flag);
		while (b->len)
		{
			// print_stacks(a, b);
			find_big_small(b);
			find_move();
			push_back(a, b);
			reset_data();
		}
		while (get_data()->rotate_left--)
			inst_exec("ra", a, b);
		if (!flag)
		{
			inst_exec("ra", a, b);
			break ;
		}
		flag = 0;
	}
}
