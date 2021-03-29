/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:24 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/25 18:49:41 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

void	solve_3_inverted(t_stack *a, t_stack *b)
{
	int top;
	int mid;
	int bot;

	top = a->numbers[2];
	mid = a->numbers[1];
	bot = a->numbers[0];
	if (top > mid && mid < bot && top < bot)
		inst_exec("rra", a, b);
	else if (top > mid && mid < bot && top > bot)
	{
		inst_exec("sa", a, b);
		inst_exec("ra", a, b);
	}
	else if (top < mid && bot > mid && bot > top)
	{
		inst_exec("sa", a, b);
		inst_exec("rra", a, b);
	}
	else if (top < mid && mid > bot && top < bot)
		inst_exec("ra", a, b);
	else if (top < mid && mid > bot && top > bot)
		inst_exec("sa", a, b);
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
		inst_exec("sa", a, b);
	else if (top > mid && mid < bot && top > bot)
		inst_exec("ra", a, b);
	else if (top < mid && mid > bot && bot > top)
	{
		inst_exec("sa", a, b);
		inst_exec("ra", a, b);
	}
	else if (top > mid && mid > bot && top > bot)
	{
		inst_exec("sa", a, b);
		inst_exec("rra", a, b);
	}
	else
		inst_exec("rra", a, b);
}
