/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:29:06 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 13:10:07 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

static void	to_top(void)
{
	t_stack	*stack;
	size_t	i;
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

static void	to_bot(void)
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

void		find_move(void)
{
	t_data *d;

	d = get_data();
	if (get_data()->b->len >= 2)
	{
		to_top();
		to_bot();
	}
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
