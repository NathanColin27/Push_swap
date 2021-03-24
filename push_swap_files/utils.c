/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:27:16 by nathan            #+#    #+#             */
/*   Updated: 2021/03/24 17:41:56 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

void	to_top(void)
{
	t_stack	*stack;
	int		i;
	t_data	*data;

	data = get_data();
	stack = data->b;
	i = 0;
	while (stack->numbers[stack->len - i - 1] != data->b_smallest)
		i++;
	data->s_rot = i;
	i = 0;
	while (stack->numbers[stack->len - i - 1] != data->b_biggest)
		i++;
	data->b_rot = i;
}

void	to_bot(void)
{
	t_stack	*stack;
	int		i;
	t_data	*data;

	data = get_data();
	stack = data->b;
	i = 0;
	while (stack->numbers[i] != data->b_smallest)
		i++;
	data->s_rrot = i;
	i = 0;
	while (stack->numbers[i] != data->b_biggest)
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
	if (d->s_rot != -1 || d->s_rrot != -1)
		d->small_flag = 1;
	else if (d->b_rot != -1 || d->b_rrot != -1)
		d->big_flag = 1;
}

void	push_back(t_stack *a, t_stack *b)
{
	t_data *d;

	d = get_data();
	if (d->s_rot > 0)
		while (d->s_rot-- > 0)
			inst_exec("rb", a, b);
	else if (d->s_rrot >= 0)
		while (d->s_rrot-- >= 0)
			inst_exec("rrb", a, b);
	else if (d->b_rot > 0)
		while (d->b_rot-- > 0)
			inst_exec("rb", a, b);
	else if (d->b_rrot >= 0)
		while (d->b_rrot-- >= 0)
			inst_exec("rrb", a, b);
	inst_exec("pa", a, b);
	int tmp = d->small_flag;
	reset_data();
	find_big_small(b);
	find_move();
	if (tmp && d->s_rot)
		inst_exec("rr", a, b);
	else if (tmp)
		inst_exec("ra", a, b);
}


int		exit_error(void)
{
	write(2, "Error\n", 7);
	//free_all()//
	exit(0);
}

