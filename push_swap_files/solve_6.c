/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:43:21 by nathan            #+#    #+#             */
/*   Updated: 2021/03/25 18:21:59 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

void	solve_2(t_stack *a, t_stack *b)
{
	if (a->numbers[0] < a->numbers[1])
		inst_exec("ra", a, b);
}

void	solve_4(t_stack *a, t_stack *b)
{
	int smallest;

	smallest = find_smallest(a);
	if (a->numbers[0] == smallest)
		inst_exec("rra", a, b);
	while (a->numbers[3] != smallest)
		inst_exec("ra", a, b);
	if (is_sorted(a))
		return ;
	inst_exec("pb", a, b);
	solve_3(a, b);
	inst_exec("pa", a, b);
}

void	solve_5(t_stack *a, t_stack *b)
{
	int median;

	median = find_median(a);
	push_median(a, b, median, 0);
	solve_3(a, b);
	if (is_sorted(b))
		inst_exec("sb", a, b);
	inst_exec("pa", a, b);
	inst_exec("pa", a, b);
}

void	solve_6(t_stack *a, t_stack *b)
{
	int median;

	median = find_median(a);
	push_median(a, b, median, 0);
	solve_3(a, b);
	solve_3_inverted(b, a);
	inst_exec("pa", a, b);
	inst_exec("pa", a, b);
	inst_exec("pa", a, b);
}

int		solve_up_to_6(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		solve_2(a, b);
	else if (a->size == 3)
		solve_3(a, b);
	else if (a->size == 4)
		solve_4(a, b);
	else if (a->size == 5)
		solve_5(a, b);
	else if (a->size == 6)
		solve_6(a, b);
	return (0);
}
