/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:08:48 by nathan            #+#    #+#             */
/*   Updated: 2021/03/11 17:55:40 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"


int	min_on_top(t_stack *a)
{
	size_t i;
	int j;

	i = 0;
	j = a->numbers[a->len - 1];
	while (i < a->len)
	{
		if (a->numbers[i] < j)
			return (0);
		i++;
	}
	return (1);
}

int	process(t_stack *a, t_stack *b, t_list **instruction)
{
	(void)instruction;
	int count = 0;
	t_instruction inst;
	while (a->len > 0)
	{
		inst = get_instruction("ra");
		while(!min_on_top(a))
		{
			// print_stacks(a, b);
			// printf("min not on top\n");
			inst.exec(a, b);
			count++;
		}
		// print_stacks(a, b);
		// printf("min on top\n");
		inst = get_instruction("pb");
		inst.exec(a, b);
		count++;
		// print_stacks(a, b);
	}
	while(b->len > 0)
	{
		inst = get_instruction("pa");
		inst.exec(a, b);
		count++;
	}
	print_stacks(a, b);
	printf("done in %d instructions", count);
	return (0);
}