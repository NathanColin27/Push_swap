/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:21:01 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/24 12:00:22 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "checker.h"

int		print_error(void)
{
	write(2, "Error\n", 7);
	return (1);
}

int main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	t_list	*instructions;

	if (argc < 2)
		return (1);
	st_a = parse_stack(argc, argv);
	if (!st_a)
		return (print_error());
	st_b = create_stack(st_a->size);
	if (!st_b)
		return (print_error());
	instructions = get_input();
	exec_instructions(instructions, st_a, st_b);
	if (valid_sort(st_a, st_b))
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}