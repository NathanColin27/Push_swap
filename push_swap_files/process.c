/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:08:48 by nathan            #+#    #+#             */
/*   Updated: 2021/03/11 23:08:50 by nathan           ###   ########.fr       */
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

// number[0] == bottom of stack
// number[len - 1] ==  top  
void push_median(t_stack *a, t_stack *b, int median)
{
	t_list *instr;
	size_t count = 0;
	print_stacks(a,b);
	printf("\nmedian = %d\n ", median);
	while (1 && count <= a->size)
	{
		if (a->numbers[a->len - 1] <= median)
			inst_exec_save("pb", &instr, a, b);
		else if (a->numbers[a->len - 1] > median)
			inst_exec_save("ra", &instr, a, b);
		
		count ++;
		print_stacks(a,b);
	}
}

int	process(t_stack *a, t_stack *b)
{

	int median;
	int count = 0;

	median = find_median(a);
	// t_instruction inst;
	push_median(a, b, median);
	print_stacks(a, b);
	printf("done in %d instructions", count);
	return (0);
}