/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:33:56 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:33:57 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Shifts down the entire stack passed as a parameter by 1, e.g. :-

BEFORE : [3, 7, 8, 1, 6, 2]

AFTER  : [0, 3, 7, 8, 1, 6]

Note that the last element gets overwritten and forgotten.
*/

void	ft_shift_down(int *stack, size_t len)
{
	while (len > 0)
	{
		ft_elem_set(stack, len, ft_elem_get(stack, len - 1));
		len--;
	}
	ft_elem_set(stack, 0, 0);
}

/*
Shifts up the entire stack passed as a parameter by 1.
The very first element gets overwritten and forgotten.
*/

void	ft_shift_up(int *stack, size_t len)
{
	size_t	x;

	if (len == 0)
		return ;
	x = -1;
	while (++x < len - 1)
		ft_elem_set(stack, x, ft_elem_get(stack, x + 1));
	ft_elem_set(stack, x, 0);
}

/*
Writes the operation to standard output and executes the instruction passed as
a parameter in the form of a function pointer.
*/

void	ft_exec_op(t_stacks *stacks, char *op, void (*f)(t_stacks *))
{
	f(stacks);
	ft_putstr_fd(op, 1);
	ft_putchar_fd('\n', 1);
}
