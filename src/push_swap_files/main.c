/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:32:42 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 16:16:49 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;

	data = get_data();
	if (argc < 2)
		return (1);
	b = create_stack(argc - 1);
	if (!b)
		ft_error();
	a = parse_stack(argc, argv, b, data);
	if (!a)
		ft_error();
	if (has_duplicates(a->numbers, a->size - 1))
		ft_error();
	if (is_sorted(a))
		return (0);
	process(a, b);
	return (0);
}
