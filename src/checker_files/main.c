/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:21:01 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 16:31:48 by nathan           ###   ########.fr       */
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
	t_stack	*a;
	t_stack	*b;
	t_list	*instructions;
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
	if (has_duplicates(a->numbers, a->size))
		ft_error();
	instructions = get_input();
	exec_instructions(instructions, a, b);
	if (valid_sort(a, b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_inst(instructions);
	ft_free_all();
	return (0);
}
