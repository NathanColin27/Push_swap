/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:13:13 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/12 12:51:23 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_instruction	get_instruction(char *arg)
{
	t_instruction tab[12] = {
		{"sa",&swap_a},
		{"sb",&swap_b},
		{"ss",&swap_ab},
		{"pa",&push_a},
		{"pb",&push_b},
		{"ra",&rot_a},
		{"rb",&rot_b},
		{"rr",&rot_ab},
		{"rra",&rev_rot_a},
		{"rrb",&rev_rot_b},
		{"rrr",&rev_rot_ab}
	};
	size_t i;
	
	i = 0;
	while (i < 11)
	{
		if (!strcmp(tab[i].name, arg))
			return (tab[i]);
		i++;
	}
	return ((t_instruction){NULL, NULL});
}

int		inst_exec(char *arg, t_stack *a, t_stack *b)
{
	t_instruction	in;
	printf("%s\n", arg);
	in = get_instruction(arg);
	if (!in.name)
		return (1);
	in.exec(a, b);
	return (0);
}