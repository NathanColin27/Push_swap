/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:08:48 by nathan            #+#    #+#             */
/*   Updated: 2021/03/23 23:41:09 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int	process(t_stack *a, t_stack *b)
{
	// print_stacks(a, b);
	if (a->size <= 6)
		solve_up_to_6(a, b);
	else if (a->size <= 100)
		solve(a,b,3);
	else
	{
		solve(a,b,8);
	}
	
	// else
	// 	solve_more();
	// push_median(a, b, find_median(a));
	// print_stacks(a, b);

	return (0);
}