/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:35:58 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 13:06:12 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

t_list	*get_input(void);

int		exec_instructions(t_list *instr, t_stack *a, t_stack *b);

int		valid_sort(t_stack *a, t_stack *b);

#endif
