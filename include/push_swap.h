/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:36:01 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/18 17:32:39 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "shared.h"
int	process(t_stack *a, t_stack *b);

int	find_median(t_stack *stack);

int	exit_error(void);

void push_median(t_stack *a, t_stack *b, int median, int flag);

int is_sorted(t_stack *a);

int	solve_up_to_6(t_stack *a, t_stack *b);

int find_smallest(t_stack *st);

void find_big_small(t_stack *st);

void solve_100(t_stack *a, t_stack *b);

int	has_lower_than_x(t_stack *st, int x);

int	has_upper_than_x(t_stack *st, int x);

void sort_array(int *array, size_t len);

void	find_move(void);

void push_back(t_stack *a, t_stack *b);

void reset_data(void);

void solve_500(t_stack *a, t_stack *b);

#endif 
