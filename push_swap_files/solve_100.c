/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:35:59 by nathan            #+#    #+#             */
/*   Updated: 2021/03/16 18:37:20 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"



void solve_100(t_stack *a, t_stack *b)
{
	int median;
	median = find_median(a);
	while(a->len)
	{
		push_median(a,b,median);
		while (b->len)
		{
			find_big_small(a);
			print_stacks(a,b);
			printf("biggest %d, smallest %d\n ", get_data()->b_biggest, get_data()->b_smallest);
			sleep(10);
		}
	
	}
	print_stacks(a,b);
}