/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:27:16 by nathan            #+#    #+#             */
/*   Updated: 2021/03/29 23:27:59 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int		chunk_end_to_top(t_stack *a, int min)
{
	int		i;

	i = 0;
	while (a->numbers[a->len - i - 1] != min - 1)
		i++;
	return (i);
}

int		chunk_end_to_bot(t_stack *a, int min)
{
	int		i;

	i = 0;
	while (a->numbers[i] != min - 1)
		i++;
	return (i);
}
