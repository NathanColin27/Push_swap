/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:16:30 by nathan            #+#    #+#             */
/*   Updated: 2021/03/11 13:30:13 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "checker.h"

/* returns 1 if stack a is correctly sorted */

int		valid_sort(t_stack *a, t_stack *b)
{
	size_t i;
	
	if (b->len > 0 || a->len != a->size)
		return (0);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->numbers[i] < a->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}
