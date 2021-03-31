/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 23:09:16 by nathan            #+#    #+#             */
/*   Updated: 2021/03/31 13:06:59 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#define MAXLONG 9223372036854775807

long	ft_atoil(const char *str)
{
	int		sign;
	long	total;

	sign = 1;
	total = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (total <= total * 10 + (*str - '0'))
		{
			total = total * 10 + (*str - '0');
			str++;
		}
		else
			return (sign == 1 ? (long)MAXLONG : (long)-MAXLONG - 1);
	}
	return (total * sign);
}

void	ft_free_all(void)
{
	t_data *data;

	data = get_data();
	if (data->a->numbers)
		free(data->a->numbers);
	if (data->a->numbers)
		free(data->b->numbers);
	free(data->a);
	free(data->b);
}

void	ft_error(void)
{
	write(2, "Error\n", 7);
	ft_free_all();
	exit(1);
}

int		has_duplicates(int *array, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
