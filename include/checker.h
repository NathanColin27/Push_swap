/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:35:58 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/30 17:08:29 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

t_list	*get_input(void);

int		exec_instructions(t_list *instr, t_stack *a, t_stack *b);

void	valid_instr(char *s);

int		valid_sort(t_stack *a, t_stack *b);

#endif
