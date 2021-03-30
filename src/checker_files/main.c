/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:21:01 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 13:06:41 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "checker.h"

void	ft_free_inst(t_list *inst)
{
	t_list *tmp;

	while (inst != NULL)
	{
		tmp = inst;
		inst = inst->next;
		free(tmp->content);
		free(tmp);
	}
}

int		main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	t_list	*instructions;
	t_data	*data;

	data = get_data();
	if (argc < 2)
		return (1);
	st_a = parse_stack(argc, argv);
	if (!st_a)
		ft_error();
	st_b = create_stack(st_a->size);
	if (!st_b)
		ft_error();
	data->a = st_a;
	data->b = st_b;
	instructions = get_input();
	exec_instructions(instructions, st_a, st_b);
	if (valid_sort(st_a, st_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_inst(instructions);
	ft_free_all();
	return (0);
}
