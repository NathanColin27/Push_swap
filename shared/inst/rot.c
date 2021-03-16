/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:50:39 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/16 18:39:29 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void			rot_a(t_stack *a, t_stack *b)
{
	int tmp;
	int i;
	
	if (a->len < 2)
		return ;
	(void)b;
	i = a->len - 1;
	tmp = a->numbers[a->len - 1];
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		i--;
	}
	a->numbers[0] = tmp;
}

void			rot_b(t_stack *a, t_stack *b)
{
	int tmp;
	int i;
	
	if (b->len < 2)
		return ;
	(void)a;
	i = b->len - 1;
	tmp = b->numbers[b->len - 1];
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		i--;
	}
	b->numbers[0] = tmp;
}

void			rot_ab(t_stack *a, t_stack *b)
{
	rot_a(a, b);
	rot_b(a, b);
}