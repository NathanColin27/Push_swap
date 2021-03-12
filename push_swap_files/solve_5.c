/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:43:21 by nathan            #+#    #+#             */
/*   Updated: 2021/03/12 13:22:00 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

//number[0] == bottom

void	solve_2(t_stack *a, t_stack *b)
{
	if (a->numbers[0] < a->numbers[1])
		inst_exec("ra", a, b);
}

void	solve_3(t_stack *a, t_stack *b)
{
	int top;
	int mid;
	int bot;
	
	top = a->numbers[2];
	mid = a->numbers[1];
	bot = a->numbers[0];
	if (top > mid && mid < bot && top < bot)
		inst_exec("ra", a, b);
	else if (top > mid && mid < bot && top > bot)
		inst_exec("ra", a, b);
	else if (top < mid && mid > bot)
	{
		inst_exec("sa", a, b);
		inst_exec("ra", a, b);
	}
	else if (top > mid && mid > bot)
	{
		inst_exec("sa", a, b);
		inst_exec("rra", a, b);
	}
	else
		inst_exec("rra", a, b);
}

int		solve_5(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		solve_2(a, b);
	else if (a->size == 3)
		solve_3(a, b);
	
	return (0);
}