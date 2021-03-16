/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:35:59 by nathan            #+#    #+#             */
/*   Updated: 2021/03/16 19:28:45 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

void	to_top() //iterate from top of stack to find index of smallest and biggest numbers
{
	t_stack	*stack;
	int		i;
	t_data	*data;
	
	data = get_data();
	stack = data->b;
	i = 0;
	while(stack->numbers[stack->len - i - 1] != data->b_smallest)
		i++;
	data->small_rot = i;
	i = 0;
	while(stack->numbers[stack->len - i - 1] != data->b_biggest)
		i++;
	data->big_rot = i;
}


void	find_move()
{
	to_top();
	printf("smallest to top : %d\nbiggest to top : %d\n", get_data()->small_rot, get_data()->big_rot);
	
}

void solve_100(t_stack *a, t_stack *b)
{
	int median;
	median = find_median(a);
	while(a->len)
	{
		push_median(a,b,median);
		while (b->len)
		{
			print_stacks(a,b);
			find_big_small(b);
			printf("smallest : %d\nbiggest : %d\n", get_data()->b_smallest, get_data()->b_biggest);
			find_move();
			sleep(30);
		}
	}
	print_stacks(a,b);
}