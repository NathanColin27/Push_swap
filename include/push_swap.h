/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:36:01 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/12 13:04:48 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	process(t_stack *a, t_stack *b);

int	find_median(t_stack *stack);

int	exit_error(void);

void push_median(t_stack *a, t_stack *b, int median);

int is_sorted(t_stack *a);

int		solve_5(t_stack *a, t_stack *b);


