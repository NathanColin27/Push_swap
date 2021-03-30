/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:41:39 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 17:13:58 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "checker.h"

void		init_data(t_data *data, t_stack *a, t_stack *b)
{
	data->a = a;
	data->b = b;
	data->b_biggest = 0;
	data->b_rot = 0;
	data->b_rrot = 0;
	data->b_smallest = 0;
	data->s_rrot = 0;
	data->s_rot = 0;
	data->small_flag = 0;
	data->rotate_left = 0;
	data->inst_count = 0;
	data->print_flag = 1;
	data->big_flag = 0;
}

static int	valid_integer(char *s)
{
	int		i;
	long	tmp;

	tmp = ft_atoil(s);
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (0);
	i = 0;
	if (s[0] && (s[0] == '-' || s[0] == '+'))
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

t_stack		*parse_stack(int ac, char **av, t_stack *b, t_data *data)
{
	t_stack	*stack;
	size_t	i;

	stack = create_stack(ac - 1);
	if (!stack)
		return (NULL);
	init_data(data, stack, b);
	i = 0;
	while (i < stack->size)
	{
		if (!valid_integer(av[i + 1]))
			ft_error();
		stack->numbers[stack->size - i - 1] = ft_atoi(av[i + 1]);
		i++;
	}
	stack->len = stack->size;
	return (stack);
}
