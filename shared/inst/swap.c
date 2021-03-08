/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:35:25 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/08 15:04:57 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static void	swap(int64_t *a, int64_t *b)
{
	int64_t	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp; 
}

void		swap_a(t_stack *a, t_stack *b)
{
	if (a->len < 2)
		return ;
	(void)b;
	swap(a->numbers[a->len - 2], a->numbers[a->len - 1]);
}

void		swap_b(t_stack *a, t_stack *b)
{
	if (b->len < 2)
		return ;
	(void)a;
	swap(b->numbers[b->len - 2], b->numbers[b->len - 1]);
}

void		swap_ab(t_stack *a, t_stack *b)
{
	if (b->len < 2 || a->len < 2)
	swap_a(a, b);
	swap_b(a, b);
}