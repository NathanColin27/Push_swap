/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:15:11 by nathan            #+#    #+#             */
/*   Updated: 2021/03/12 12:55:57 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

// number[0] == bottom of stack
// number[len - 1] ==  top  
void push_median(t_stack *a, t_stack *b, int median)
{
	size_t count = 0;
	print_stacks(a,b);
	while (1 && count <= a->size)
	{
		if (a->numbers[a->len - 1] <= median)
			inst_exec("pb", a, b);
		else if (a->numbers[a->len - 1] > median)
			inst_exec("ra", a, b);
		count ++;
	}
}

void sort_array(int *array, size_t len)
{
	size_t i;
	size_t j;
	int tmp;

	i = 0;
	tmp = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
			j++;
		}
		i++;
	}

}

int	find_median(t_stack *stack)
{
	int *array;
	int ret;
	size_t i;
	
	i = 0;
	if (!(array = (int*)malloc(sizeof(int)*stack->len)))
		printf("malloc error");
	while (i < stack->len)
	{
		array[i] = stack->numbers[i];
		i++;
	}
	sort_array(array, stack->len);
	ret = array[(stack->len)/2];
	free(array);
	return (ret);
}