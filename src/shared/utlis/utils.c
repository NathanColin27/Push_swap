/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 23:09:16 by nathan            #+#    #+#             */
/*   Updated: 2021/03/30 13:03:05 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ft_free_all(void)
{
	t_data *data;

	data = get_data();
	free(data->a->numbers);
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
