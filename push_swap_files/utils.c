/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:27:16 by nathan            #+#    #+#             */
/*   Updated: 2021/03/12 13:26:05 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int		exit_error(void)
{
	write(2, "Error\n", 7);
	//free_all()//
	exit(0);
}

int is_sorted(t_stack *a)
{
	size_t i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->numbers[i] < a->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}