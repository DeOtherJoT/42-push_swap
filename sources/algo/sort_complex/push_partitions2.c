#include "../../../includes/push_swap.h"

void	push_partitions(t_stacks *stacks, int limit)
{
	size_t	ctr;

	while (stacks->stack_a[0] <= limit && stacks->len_a > 0)
		ft_exec_op(stacks, "pb", op_pb);
	while (stacks->stack_a[stacks->len_a - 1] <= limit && stacks->len_a > 0)
	{
		ft_exec_op(stacks, "rra", op_rra);
		ft_exec_op(stacks, "pb", op_pb);
	}
	while ((int)stacks->len_b != limit)
	{
		ctr = -1;
		while (++ctr < stacks->len_a)
		{
			if (stacks->stack_a[ctr] <= limit && stacks->len_a > 0)
				move_elem_a(stacks, stacks->stack_a[ctr]);
		}
	}
}

void	handle_partitions(t_stacks *stacks, int *limits, size_t part_count)
{
	size_t	i;

	i = -1;
	while (++i < part_count)
	{
		ft_print_stacks(stacks);
		push_partitions(stacks, limits[i]);
	}
}