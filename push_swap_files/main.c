/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:32:42 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/19 13:42:17 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

void init_data(t_data *data, t_stack *a, t_stack *b)
{
	data->a = a;
	data->b = b;
	data->b_biggest = 0;
	data->b_rot = 0;
	data->b_rrot = 0;
	data->b_smallest = 0;
	data->s_rrot = 0;
	data->s_rot = 0;
	data->small_flag = 0;
	data->rotate_left = 0;
	data->inst_count = 0;
	
	
	data->big_flag = 0;
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;

	data = get_data();
	if (argc < 2)
		return (1);
	a = parse_stack(argc, argv);
	if (!a)
		return (exit_error());
	b = create_stack(a->size);
	if (!b)
		return (exit_error());
	init_data(data,a ,b);
	if (is_sorted(a))
		return (0);
	process(a, b);
	print_stacks(a,b);
	printf()
	return (0);
}