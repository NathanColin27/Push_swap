/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:41:39 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/08 16:32:08 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "libft.h"

static int	valid_integer(char *s)
{
	int i;
	
	i = 0;
	if (s[0] && (s[0] ==  '-' || s[0] == '+'))
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

t_stack *parse_stack(int ac, char **av)
{
	t_stack *stack;
	int i;

	stack = create_stack(ac - 1);
	if (!stack)
		return (NULL);
	while (i < stack->size)
	{	
		stack->numbers[stack->size - i - 1] = ft_atoi(av[i + 1]);
		i++;
	}
	stack->len = stack->size;
	return (stack);
}
