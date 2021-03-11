/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:36:04 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/11 22:40:50 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

/* structs */

typedef	struct	s_stack
{
	int64_t	*numbers;
	size_t	size;
	size_t	len;
	t_list	*partitions;
}				t_stack;

typedef struct	s_instruction
{
	char *name;
	void (* exec)(t_stack *, t_stack *);
}				t_instruction;


/* stack */

t_stack		*create_stack(size_t size);

t_stack		*parse_stack(int ac, char **av);

void		print_stacks(t_stack *st_a, t_stack *st_b);

/* instructions */

t_instruction	get_instruction(char *arg);

int				inst_exec_save(char *arg, t_list **inst, t_stack *a, t_stack *b);

void			swap_a(t_stack *a, t_stack *b);

void			swap_b(t_stack *a, t_stack *b);

void			swap_ab(t_stack *a, t_stack *b);

void			push_a(t_stack *a, t_stack *b);

void			push_b(t_stack *a, t_stack *b);

void			rot_a(t_stack *a, t_stack *b);

void			rot_b(t_stack *a, t_stack *b);

void			rot_ab(t_stack *a, t_stack *b);

void			rev_rot_a(t_stack *a, t_stack *b);

void			rev_rot_b(t_stack *a, t_stack *b);

void			rev_rot_ab(t_stack *a, t_stack *b);



