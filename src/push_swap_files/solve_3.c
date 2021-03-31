/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:24 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/31 15:05:04 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

void	solve_3_inverted(t_stack *a, t_stack *b)
{
	int top;
	int mid;
	int bot;
	
	top = b->numbers[2];
	mid = b->numbers[1];
	bot = b->numbers[0];
	if (top > mid && mid < bot && top < bot)
		inst_exec("rrb", a, b);
	else if (top > mid && mid < bot && top > bot)
	{
		inst_exec("sb", a, b);
		inst_exec("rb", a, b);
	}
	else if (top < mid && bot > mid && bot > top)
	{
		inst_exec("sb", a, b);
		inst_exec("rrb", a, b);
	}
	else if (top < mid && mid > bot && top < bot)
		inst_exec("rb", a, b);
	else if (top < mid && mid > bot && top > bot)
		inst_exec("sb", a, b);
}

void	solve_3(t_stack *a, t_stack *b)
{
	int top;
	int mid;
	int bot;
	
	if (is_sorted(a))
		return ;
	top = a->numbers[a->len - 1];
	mid = a->numbers[a->len - 2];
	bot = a->numbers[a->len - 3];
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
