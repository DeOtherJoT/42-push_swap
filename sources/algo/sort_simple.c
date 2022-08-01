#include "../../includes/push_swap.h"

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

void	ft_sort_simple(t_stacks *stacks)
{
	while (stacks->len_a > 3)
		ft_exec_op(stacks, "pb", op_pb);
	ft_sort_three(stacks, stacks->stack_a, stacks->stack_b);
	
}