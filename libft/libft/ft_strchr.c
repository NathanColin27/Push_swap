/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:28:17 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/21 10:32:08 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strchr() function locates the first occurrence of c
**	(converted to a char) in the string pointed to by s. The terminating null
**  character is considered to be part of the string; therefore if c is `\0',
**	the functions locate the terminating `\0'.
*/

char	*ft_strchr(char const *str, int c)
{
	char a;

	a = c;
	while (*str)
	{
		if (*str == a)
			return (char *)(str);
		str++;
	}
	if (*str == a)
		return (char *)(str);
	return (NULL);
}
