/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ins_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:33:29 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:33:31 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Shifts all elements of stack a up by 1. The first element becomes the
last element.
*/

void	op_ra(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_a < 2)
		return ;
	temp = ft_elem_get(stacks->stack_a, 0);
	ft_shift_up(stacks->stack_a, stacks->len_a);
	ft_elem_set(stacks->stack_a, stacks->len_a - 1, temp);
}

/*
Shifts all elements of stack b up by 1. The first element becomes the
last element.
*/

void	op_rb(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_b < 2)
		return ;
	temp = ft_elem_get(stacks->stack_b, 0);
	ft_shift_up(stacks->stack_b, stacks->len_b);
	ft_elem_set(stacks->stack_b, stacks->len_b - 1, temp);
}

/*
Executes the operations ra and rb together as one operation.
*/

void	op_rr(t_stacks *stacks)
{
	op_ra(stacks);
	op_rb(stacks);
}

/*
Shifts all elements of stack a down by 1. The last element becomes
the first element.
*/

void	op_rra(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_a < 2)
		return ;
	temp = ft_elem_get(stacks->stack_a, stacks->len_a - 1);
	ft_shift_down(stacks->stack_a, stacks->len_a - 1);
	ft_elem_set(stacks->stack_a, 0, temp);
}

/*
Shifts all elements of stack b down by 1. The last element becomes
the first element.
*/

void	op_rrb(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_b < 2)
		return ;
	temp = ft_elem_get(stacks->stack_b, stacks->len_b - 1);
	ft_shift_down(stacks->stack_b, stacks->len_b - 1);
	ft_elem_set(stacks->stack_b, 0, temp);
}
