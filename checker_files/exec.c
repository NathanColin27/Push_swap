/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:58:01 by nathan            #+#    #+#             */
/*   Updated: 2021/03/11 13:12:52 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "checker.h"

int	exec_instructions(t_list *instr, t_stack *a, t_stack *b)
{
	t_list			*copy;
	t_instruction	inst;

	copy = instr;
	while (copy)
	{
		inst = get_instruction(copy->content);
		if(!inst.name)
			return (1); // write proper exit error
		inst.exec(a, b);
		copy = copy->next;
	}
	return (1);
}