/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:07:32 by nathan            #+#    #+#             */
/*   Updated: 2021/03/30 17:13:36 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "checker.h"

void	valid_instr(char *line)
{
	if (get_instruction(line).name == NULL)
	{
		free(line);
		ft_error();
	}
}

t_list	*get_input(void)
{
	t_list	*head;
	t_list	*node;
	char	*line;
	char	*tmp;
	int		ret;

	head = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (line[0] != 0)
		{
			valid_instr(line);
			tmp = ft_strdup(line);
			node = ft_lstnew(tmp);
			if (!node)
				return (NULL);
			ft_lstadd_back(&head, node);
		}
		free(line);
	}
	return (head);
}
