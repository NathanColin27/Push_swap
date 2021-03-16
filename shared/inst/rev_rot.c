/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:19:36 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/16 18:39:29 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void			rev_rot_a(t_stack *a, t_stack *b)
{
	int tmp;
	size_t i;
	
	if (a->len < 2)
		return ;
	(void)b;
	i = 0;
	tmp = a->numbers[0];
	while (i < a->len - 1)
	{
		a->numbers[i] = a->numbers[i + 1];
		i++;
	}
	a->numbers[a->len - 1] = tmp;
}

void			rev_rot_b(t_stack *a, t_stack *b)
{
	int tmp;
	size_t i;
	
	if (b->len < 2)
		return ;
	(void)a;
	i = 0;
	tmp = b->numbers[0];
	while (i < b->len - 1)
	{
		b->numbers[i] = b->numbers[i + 1];
		i++;
	}
	b->numbers[b->len - 1] = tmp;
}

void			rev_rot_ab(t_stack *a, t_stack *b)
{
	rev_rot_a(a, b);
	rev_rot_b(a, b);
}