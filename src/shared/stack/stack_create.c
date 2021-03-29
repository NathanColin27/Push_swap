/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:59:53 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/19 10:56:41 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_stack		*create_stack(size_t size)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = size;
	stack->len = 0;
	stack->numbers = ft_calloc(size, sizeof(int));
	if (!stack->numbers)
		return (NULL);
	return (stack);
}
