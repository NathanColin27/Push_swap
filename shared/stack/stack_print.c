/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:15:09 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/08 15:15:36 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void stacks_print(t_stack *st_a, t_stack *st_b)
{
	printf("stack A (%zu):\n>", st_a->len);
	for (size_t i = 0; i < st_a->len; i++)
	{
		printf(" %lld", st_a->numbers[i]);
		if (stack_isprt(st_a, i))
			printf(" |");
	}
	printf("\n");
	printf("stack B (%zu):\n>", st_b->len);
	for (size_t i = 0; i < st_b->len; i++)
	{
		printf(" %lld", st_b->numbers[i]);
		if (stack_isprt(st_b, i))
			printf(" |");
	}
	printf("\n");
}