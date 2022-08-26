/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:34:18 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:34:20 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
This function returns the right target in stack_a that is to be moved to the
top of the stack_a. This makes it so that when the parameter elem is pushed
to stack_a, it would be in the correct position.
*/

int	get_target(int *stack, size_t len, int elem, int flag)
{
	size_t	ctr;
	int		ret;

	ctr = 0;
	ret = stack[0];
	if (flag == 0)
	{
		while (++ctr < len)
		{
			if (ret > stack[ctr])
				ret = stack[ctr];
		}
	}
	else
	{
		while (++ctr < len)
		{
			if (stack[ctr - 1] < elem && stack[ctr] > elem)
				ret = stack[ctr];
		}
	}
	return (ret);
}

/*
Get the amount of moves that it would take to move the correct target to the
top of stack_a. The end goal here is to shift stack_a so that what is pushed
from stack_b is in the correct position. The total amount of moves for ra
and rra are saved to the t_data struct here.
*/

void	get_moves_a(t_stacks *stacks, t_data *ret)
{
	size_t	x;
	int		target;

	if (ft_isborder(ret->elem, stacks->stack_a, stacks->len_a) == 1)
		target = get_target(stacks->stack_a, stacks->len_a, ret->elem, 0);
	else
		target = get_target(stacks->stack_a, stacks->len_a, ret->elem, 1);
	x = ft_elem_index(stacks->stack_a, target);
	ret->do_ra = x;
	ret->do_rra = stacks->len_a - x;
}

/*
Get the amount of moves that it would take to move an element in stack_b to
the top of stack_b. Here only either the total amount of moves of rb or rrb
is saved to the t_data struct.
*/

void	get_moves_b(t_stacks *stacks, t_data *ret)
{
	size_t	x;
	int		target;

	target = ret->elem;
	x = ft_elem_index(stacks->stack_b, target);
	if (x <= ((stacks->len_b - 1) - x))
	{
		ret->do_rrb = 0;
		ret->do_rb = x;
	}
	else
	{
		ret->do_rb = 0;
		ret->do_rrb = stacks->len_b - x;
	}
}

/*
This function takes all the total amount of ra and rra and either rb or rrb
and cleans them up to a final decision that will acheive the intended result
in the least amount of moves. In the end, the t_data struct holds the amount
of times to execute the instructions ra, rra, rb, rrb, rr, or rrr.
*/

void	process_data(t_data *ret)
{
	if (ret->do_rrb == 0)
	{
		if ((ret->do_rb + ret->do_rra) < ft_most(ret->do_rb, ret->do_ra))
			process_one(ret);
		else
			process_two(ret);
	}
	else
	{
		if ((ret->do_rrb + ret->do_ra) < ft_most(ret->do_rrb, ret->do_rra))
			process_three(ret);
		else
			process_four(ret);
	}
}

/*
Returns a new t_data node, which holds the information of a particular
element in stack_b about how many moves it would take to move it back to
stack_a. It is optimised to use rr and rrr when necessary.
*/

t_data	*ft_data_new(t_stacks *stacks, size_t i)
{
	t_data	*ret;

	ret = malloc(sizeof(t_data));
	if (!ret)
		err_msg("Error at t_data elem creation.");
	ret->elem = stacks->stack_b[i];
	get_moves_a(stacks, ret);
	get_moves_b(stacks, ret);
	process_data(ret);
	return (ret);
}
