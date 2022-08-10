#include "../../includes/push_swap.h"

/*
Hardcoded solutions for the five different scenarios that a stack with
three elements could be sorted.
*/

void	ft_sort_three(t_stacks *stacks, int *stack, size_t len)
{
	if (ft_get_state(stack, len) == SORTED_DES)
	{
		ft_exec_op(stacks, "sa", op_sa);
		ft_exec_op(stacks, "rra", op_rra);
	}
	else if (stack[2] > stack[0] && stack[0] > stack[1])
		ft_exec_op(stacks, "sa", op_sa);
	else if (stack[0] > stack[2] && stack[2] > stack[1])
		ft_exec_op(stacks, "ra", op_ra);
	else if (stack[1] > stack[0] && stack[0] > stack[2])
		ft_exec_op(stacks, "rra", op_rra);
	else
	{
		ft_exec_op(stacks, "sa", op_sa);
		ft_exec_op(stacks, "ra", op_ra);
	}
}

/*
For situations with 3 elements, there is no need to use stack_b, and the
elements are sorted in ft_sort_three().

For situations with 4 - 5 elements, the two smallest elements are pushed to
stack_b using move_elem_a in such a way that they are in descending order.
Then what is left in stack_a is sorted using ft_sort_thre(), and these are in
the correct spots. What's left to do is to push the elements in stack_b
back to stack_a, already in the sorted positions.
*/

void	ft_sort_simple(t_stacks *stacks)
{
	size_t	ctr;

	ctr = 1;
	while (stacks->len_a > 3)
	{
		move_elem_a(stacks, ctr);
		ctr++;
	}
	ft_sort_three(stacks, stacks->stack_a, stacks->len_a);
	while (stacks->len_b > 0)
		ft_exec_op(stacks, "pa", op_pa);
}