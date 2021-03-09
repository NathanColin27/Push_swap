/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:32:42 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/09 10:44:16 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int		print_error(void)
{
	// write(2, "Error", 6);
	return (1);
}

int main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc < 2)
		return (1);
	st_a = parse_stack(argc, argv);
	if (!st_a)
		return (print_error());
	st_b = create_stack(st_a->size);
	if (!st_b)
		return (print_error());
	
	return (0);
}