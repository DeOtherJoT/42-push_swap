/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:15:39 by jthor             #+#    #+#             */
/*   Updated: 2022/09/03 14:15:41 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	exit_bonus(t_stacks *stacks, int flag);
int		get_op_index(char *op);
void	exec_inst(t_stacks *stacks, void (*op_arr[11]) (t_stacks *), char *op);
void	init_op_arr(void (*op_arr[11]) (t_stacks *));

#endif