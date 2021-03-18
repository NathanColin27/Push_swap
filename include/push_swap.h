/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:36:01 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/18 12:24:24 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_data
{
	t_stack *a;
	t_stack *b;

	int		b_biggest;
	int		b_smallest;

	int		s_rot;
	int		s_rrot;
	int		b_rot;
	int		b_rrot;
	int		small_flag;
	int 	big_flag;
}				t_data;

int	process(t_stack *a, t_stack *b);

int	find_median(t_stack *stack);

int	exit_error(void);

void push_median(t_stack *a, t_stack *b, int median);

int is_sorted(t_stack *a);

int	solve_up_to_6(t_stack *a, t_stack *b);

int find_smallest(t_stack *st);

void find_big_small(t_stack *st);

void solve_100(t_stack *a, t_stack *b);


t_data		*get_data();