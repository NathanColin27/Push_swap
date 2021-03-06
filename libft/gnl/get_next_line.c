/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:55:48 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/29 13:59:57 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_del_tab(char **tab)
{
	if (*tab != NULL)
		free(*tab);
	*tab = NULL;
	return (-1);
}

static int	add_line(char **tab, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*tab)[len] != '\0' && (*tab)[len] != '\n')
		len++;
	if ((*tab)[len] == '\n')
	{
		*line = ft_substr(*tab, 0, len);
		tmp = ft_strdup(&((*tab)[len + 1]));
		free(*tab);
		*tab = tmp;
	}
	else
	{
		*line = ft_strdup(*tab);
		ft_del_tab(tab);
	}
	return (1);
}

int			return_value(int fd, int ret, char **line, char **tab)
{
	if (ret < 0)
	{
		ft_del_tab(tab);
		return (-1);
	}
	else if (ret == 0 && tab[fd] == NULL)
	{
		*line = ft_calloc(sizeof(char) * 1, 1);
		return (0);
	}
	else
	{
		add_line(&tab[fd], line);
		if (ret == 0 && tab[fd] == NULL)
			return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*tab[OPEN_MAX];
	char		*tmp;

	ret = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (!ft_strchr(tab[fd], '\n') && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (tab[fd] == NULL)
			tab[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(tab[fd], buf);
			free(tab[fd]);
			tab[fd] = tmp;
		}
	}
	return (return_value(fd, ret, line, tab));
}
