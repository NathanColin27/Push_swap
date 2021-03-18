/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:35:59 by nathan            #+#    #+#             */
/*   Updated: 2021/03/18 22:47:10 by nathan           ###   ########.fr       */
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
	data->s_rot = i;
	i = 0;
	while(stack->numbers[stack->len - i - 1] != data->b_biggest)
		i++;
	data->b_rot = i;
}

void	to_bot() //iterate from bot of stack to find index of smallest and biggest numbers
{
	t_stack	*stack;
	int		i;
	t_data	*data;
	
	data = get_data();
	stack = data->b;
	i = 0;
	while(stack->numbers[i] != data->b_smallest)
		i++;
	data->s_rrot = i;
	i = 0;
	while(stack->numbers[i] != data->b_biggest)
		i++;
	data->b_rrot = i;
	
	if (data->b_rot <= data->b_rrot)
		data->b_rrot = -1;
	else
		data->b_rot = -1;
	if (data->s_rot <= data->s_rrot)
		data->s_rrot = -1;
	else
		data->s_rot = -1;
}

void	find_move(void)
{
	t_data *d;

	d = get_data();
	to_top();
	to_bot();
	
	if (d->b_rot >= d->s_rot && d->b_rot >= d->s_rrot)
		d->b_rot = -1;
	else if (d->b_rrot >= d->s_rot && d->b_rrot >= d->s_rrot)
		d->b_rrot = -1;
	else if (d->s_rot >= d->b_rot && d->s_rot >= d->b_rrot)
		d->s_rot = -1;
	else if (d->s_rrot >= d->b_rot && d->s_rrot >= d->b_rrot)
		d->s_rrot = -1;
	

	if (d->s_rot !=  -1 || d->s_rrot != -1)
		d->small_flag = 1;
	else if (d->b_rot != -1 || d-> b_rrot != -1)
		d->big_flag = 1;
	// printf("smallest to top : %d\nbiggest to top : %d\n", get_data()->s_rot, get_data()->b_rot);
	// printf("smallest to bot : %d\nbiggest to bot : %d\n", get_data()->s_rrot, get_data()->b_rrot);
}

void push_back(t_stack *a, t_stack *b)
{
	t_data *d;

	d = get_data();
	if(d->s_rot > 0)
		while (d->s_rot-- > 0)
			inst_exec("rb",a ,b );
	else if(d->s_rrot >= 0)
		while (d->s_rrot-- >= 0)
			inst_exec("rrb",a ,b );
	else if(d->b_rot > 0)
		while (d->b_rot-- > 0)
			inst_exec("rb",a ,b );
	else if(d->b_rrot >= 0)
		while (d->b_rrot-- >= 0)
			inst_exec("rrb",a ,b );
	inst_exec("pa", a, b);
	d->small_flag ? inst_exec("ra",a, b): 0;
	d->big_flag ? d->rotate_left++ : 0;
	
}

void reset_data(void)
{
	t_data *data;

	data =  get_data();
	data->b_biggest = 0;
	data->b_rot = 0;
	data->b_rrot = 0;
	data->b_smallest = 0;
	data->big_flag = 0;
	data->small_flag = 0;
	data->s_rot = 0;
	data->s_rrot = 0;
}

void solve_100(t_stack *a, t_stack *b)
{
	int median;
	int flag;

	flag  = 1;
	median = find_median(a);
	while(a->len)
	{
		push_median(a,b,median, flag);
		while (b->len)
		{
			print_stacks(a,b);
			find_big_small(b);
			find_move();
			push_back(a, b);
			reset_data();
			// sleep(1);
		}
		while (get_data()->rotate_left--)
			inst_exec("ra", a, b);
		if(!flag)
		{
			inst_exec("ra", a, b);
			break ;
		}
			
		flag = 0;
		
	}
	print_stacks(a,b);
}