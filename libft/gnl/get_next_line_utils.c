/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:55:45 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 11:59:13 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) != 0)
	{
		if (start < ft_strlen(s))
			while (i < len && *(s + start + i))
			{
				result[i] = *(s + start + i);
				i++;
			}
		result[i] = '\0';
	}
	return (result);
}

char		*ft_strchr(char const *str, int c)
{
	char a;

	if (!str)
		return (NULL);
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
