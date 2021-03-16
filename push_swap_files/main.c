/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:32:42 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/16 18:26:48 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

t_data	*get_data()
{
	static t_data data;
	return (&data);
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
	if (is_sorted(a))
		return (0);
	process(a, b);
	return (0);
}