/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:32:42 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/11 15:30:10 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int		print_error(void)
{
	// write(2, "Error", 6);
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
	process(st_a, st_b, &instructions);
	
	return (0);
}