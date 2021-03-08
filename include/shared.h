/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:36:04 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/08 16:45:47 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* structs */

typedef	struct	s_stack
{
	int64_t	*numbers;
	size_t	size;
	size_t	len;
	t_list	*partitions;
}				t_stack;

/* stack */

t_stack		*create_stack(size_t size);

/* instructions */
void			swap_a(t_stack *a, t_stack *b);

void			swap_b(t_stack *a, t_stack *b);

void			swap_ab(t_stack *a, t_stack *b);

void			push_a(t_stack *a, t_stack *b);

void			push_b(t_stack *a, t_stack *b);

void			push_ab(t_stack *a, t_stack *b);

void			rot_a(t_stack *a, t_stack *b);

void			rot_b(t_stack *a, t_stack *b);

void			rot_ab(t_stack *a, t_stack *b);

void			rev_rot_a(t_stack *a, t_stack *b);

void			rev_rot_b(t_stack *a, t_stack *b);

void			rev_rot_ab(t_stack *a, t_stack *b);



