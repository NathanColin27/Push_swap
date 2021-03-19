/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:09:32 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/19 11:06:36 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	push_a(t_stack *a, t_stack *b)
{
	if (b->len < 1)
		return ;
	a->numbers[a->len] = b->numbers[b->len - 1];
	b->numbers[b->len - 1] = 0;
	b->len -= 1;
	a->len += 1;
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->len < 1)
		return ;
	b->numbers[b->len] = a->numbers[a->len - 1];
	a->numbers[a->len - 1] = 0;
	a->len -= 1;
	b->len += 1;
}
