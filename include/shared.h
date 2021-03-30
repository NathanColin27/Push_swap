/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:36:04 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 14:34:53 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "../libft/includes/libft.h"

typedef	struct	s_stack
{
	int		*numbers;
	size_t	size;
	size_t	len;
	t_list	*partitions;
}				t_stack;

typedef struct	s_instruction
{
	char *name;
	void (* exec)(t_stack *, t_stack *);
}				t_instruction;

typedef struct	s_data
{
	t_stack *a;
	t_stack *b;

	int		b_biggest;
	int		b_smallest;
	int		chunk_top;
	int		s_rot;
	int		s_rrot;
	int		b_rot;
	int		b_rrot;
	int		small_flag;
	int		big_flag;
	int		rotate_left;
	int		inst_count;
	int		print_flag;
}				t_data;

t_stack			*create_stack(size_t size);

t_stack			*parse_stack(int ac, char **av);

void			print_stacks(t_stack *st_a, t_stack *st_b);

t_instruction	get_instruction(char *arg);

int				inst_exec(char *arg, t_stack *a, t_stack *b);

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

t_data			*get_data(void);

void			ft_error(void);

void			ft_free_all(void);

#endif
