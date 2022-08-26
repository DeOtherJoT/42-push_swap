/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:35:19 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:37:13 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Checks if the input, initialised to stack a is already sorted or has only
1 element or has no elements. In these cases, no action is necessary and
end the program.
As an added function, the order is unsorted but there's only two elements,
then they only need to be swapped, and then end the program.
*/

void	first_check(t_stacks *stacks, int *stack, size_t len)
{
	if (ft_get_state(stack, len) == SORTED_ASC
		|| ft_get_state(stack, len) == NO_ACT)
		exit_prog(stacks);
	if (len == 2)
	{
		ft_exec_op(stacks, "sa", op_sa);
		exit_prog(stacks);
	}
}

/*
Start the stack sorting algorithm.
There are four paths :-
	A) 2 elements or the stack is already sorted.
		- This is handled by first_check()
	B) 3 - 5 elements.
		- This is handled by ft_sort_simple()
	C) Everything else.
		- gg.com
This function decides which sorting algorithm to do based on len_a. 
*/

void	sort_stacks(t_stacks *stacks)
{
	first_check(stacks, stacks->stack_a, stacks->len_a);
	if (stacks->len_a <= 5)
		ft_sort_simple(stacks);
	else
		ft_sort_complex(stacks);
}
