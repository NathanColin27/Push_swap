/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:15:09 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/16 18:41:45 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void print_stacks(t_stack *st_a, t_stack *st_b)
{
	printf("stack A (%zu):\n|", st_a->len);
	for (size_t i = 0; i < st_a->len; i++)
	{
		printf(" %d", st_a->numbers[i]);
		// if (stack_isprt(st_a, i))
		// 	printf(" |");
	}
	printf(" <\n");
	printf("stack B (%zu):\n|", st_b->len);
	for (size_t i = 0; i < st_b->len; i++)
	{
		printf(" %d", st_b->numbers[i]);
		// if (stack_isprt(st_b, i))
		// 	printf(" |");
	}
	printf(" <\n");
}