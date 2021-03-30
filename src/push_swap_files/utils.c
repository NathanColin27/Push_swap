/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:27:16 by nathan            #+#    #+#             */
/*   Updated: 2021/03/30 14:16:53 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "push_swap.h"

int		chunk_end_to_top(t_stack *a, int end)
{
	int		i;

	i = 0;
	while (a->numbers[a->len - i - 1] != end - 1)
		i++;
	return (i);
}

int		chunk_end_to_bot(t_stack *a, int end)
{
	int		i;

	i = 0;
	while (a->numbers[i] != end - 1)
		i++;
	return (i);
}

int		is_sorted(t_stack *a)
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
