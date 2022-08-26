/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:34:09 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:34:11 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Looks for the element that would be pushed with the least amount of moves.
If there are multiple, push the first instance.
*/

t_data	*filter_list(t_data **list, size_t len)
{
	size_t	ctr;
	int		temp_total;
	size_t	temp_index;

	ctr = 0;
	temp_index = 0;
	temp_total = list[ctr]->total_moves;
	while (++ctr < len)
	{
		if (temp_total > list[ctr]->total_moves)
		{
			temp_total = list[ctr]->total_moves;
			temp_index = ctr;
		}
	}
	return (list[temp_index]);
}

/*
Executes the instructions that are necessary in order to rotate the
stacks so that the intended element can be pushed to the correct spot
in stack_a.
*/

void	complex_move(t_stacks *stacks, t_data *ins)
{
	while ((ins->do_ra)-- > 0)
		ft_exec_op(stacks, "ra", op_ra);
	while ((ins->do_rb)-- > 0)
		ft_exec_op(stacks, "rb", op_rb);
	while ((ins->do_rr)-- > 0)
		ft_exec_op(stacks, "rr", op_rr);
	while ((ins->do_rra)-- > 0)
		ft_exec_op(stacks, "rra", op_rra);
	while ((ins->do_rrb)-- > 0)
		ft_exec_op(stacks, "rrb", op_rrb);
	while ((ins->do_rrr)-- > 0)
		ft_exec_op(stacks, "rrr", op_rrr);
	ft_exec_op(stacks, "pa", op_pa);
}

/*
Frees the list of t_data nodes.
*/

void	ft_free_list(t_data **list, size_t len)
{
	size_t	ctr;

	ctr = -1;
	while (++ctr < len)
		free(list[ctr]);
	free(list);
}

/*
With every invocation, a list of t_data nodes are made, each corresponding
to an element in stack_b, which tells us how many moves have to be executed
on both stack_a and stack_b so that the particular element is pushed to the
correct location in stack_a. After the list is created, the element which
would take the least amount of moves is pushed to stack_a.
*/

void	smart_rotate(t_stacks *stacks)
{
	t_data	**list;
	size_t	i;

	list = malloc(sizeof(t_data *) * stacks->len_b);
	if (!list)
		err_msg("Error at t_data list creation.");
	i = 0;
	while (i < stacks->len_b)
	{
		list[i] = ft_data_new(stacks, i);
		i++;
	}
	complex_move(stacks, filter_list(list, stacks->len_b));
	ft_free_list(list, stacks->len_b + 1);
}

/*
Driver function for the smart rotate algorithm. Basically executes smart
rotate until stack_b is empty. Since with every call for smart_rotate, an
element is pushed to stack_a, there is no worry of infinite loops here.
*/

void	begin_sort(t_stacks *stacks)
{
	while (stacks->len_b != 0)
		smart_rotate(stacks);
}
