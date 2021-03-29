/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:07:32 by nathan            #+#    #+#             */
/*   Updated: 2021/03/29 23:24:47 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "checker.h"

t_list	*get_input(void)
{
	t_list	*head;
	t_list	*node;
	char	*line;

	head = NULL;
	int ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		node = ft_lstnew(line);
		if (!node)
			return (NULL);
		ft_lstadd_back(&head, node);
	}
	node = ft_lstnew(line);
	if (!node)
		return (NULL);
	ft_lstadd_back(&head, node);
	return (head);
}
