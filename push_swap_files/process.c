/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:08:48 by nathan            #+#    #+#             */
/*   Updated: 2021/03/12 13:05:52 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int	process(t_stack *a, t_stack *b)
{
	print_stacks(a,b);
	if (a->size <= 5)
		solve_5(a, b);
	// else if (a->size <= 100)
	// 	solve_100();
	// else
	// 	solve_more();
	// push_median(a, b, find_median(a));
	print_stacks(a, b);

	return (0);
}