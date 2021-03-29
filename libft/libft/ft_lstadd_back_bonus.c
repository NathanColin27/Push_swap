/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:55:29 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/29 13:55:49 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the element new at the end of the list.
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else if (alst && *alst)
	{
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
