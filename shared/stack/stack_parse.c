/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:41:39 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/11 13:38:08 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
// #include "libft.h"

static int	valid_integer(char *s)
{
	int i;
	
	i = 0;
	if (s[0] && (s[0] ==  '-' || s[0] == '+'))
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

t_stack *parse_stack(int ac, char **av)
{
	t_stack *stack;
	size_t i;

	stack = create_stack(ac - 1);
	if (!stack)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{	
		if (!valid_integer(av[i + 1]))
			return (0);
		stack->numbers[stack->size - i - 1] = ft_atoi(av[i + 1]);
		i++;
	}
	stack->len = stack->size;
	return (stack);
}
