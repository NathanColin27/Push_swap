/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:15:11 by nathan            #+#    #+#             */
/*   Updated: 2021/03/18 22:40:30 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int	has_between_min_max(t_stack *st, int min, int max)
{
	size_t i;

	i = 0;
	while (i < st->len)
	{
		if (st->numbers[i] >= min && st->numbers[i] <= max)
			return (1);
		i++;
	}
	return (0);
}

int	has_lower_than_x(t_stack *st, int x)
{
	size_t i;

	i = 0;
	while (i < st->len)
	{
		if (st->numbers[i] < x)
			return (1);
		i++;
	}
	return (0);
}

int	has_upper_than_x(t_stack *st, int x)
{
	size_t i;

	i = 0;
	while (i < st->len)
	{
		if (st->numbers[i] >= x)
			return (1);
		i++;
	}
	return (0);
}

// number[0] == bottom of stack
// number[len - 1] == top
void push_median(t_stack *a, t_stack *b, int median, int flag)
{
	size_t count = 0;
	if (flag == 1)
	{
		while (count <= a->size && has_lower_than_x(a, median))
		{
			if (a->numbers[a->len - 1] < median)
				inst_exec("pb", a, b);
			else if (a->numbers[a->len - 1] >= median && has_lower_than_x(a, median))
				inst_exec("ra", a, b);
			count ++;
		}
	}
	else {
		while (count <= a->size && has_upper_than_x(a, median))
		{
			if (a->numbers[a->len - 1] >= median)
				inst_exec("pb", a, b);
			else if (a->numbers[a->len - 1] < median && has_upper_than_x(a, median))
				inst_exec("ra", a, b);
			count ++;
		}
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