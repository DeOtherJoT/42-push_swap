#include "../../includes/push_swap.h"

void	first_check(t_stacks *stacks, int *stack, size_t len)
{
	int	x;

	x = 0;
	while (x < len - 1)
	{
		if (ft_elem_get(stack, x) > ft_elem_get(stack, x + 1))
			return ;
	}
	exit_prog(stacks);
}

void	sort_stacks(t_stacks *stacks)
{
	first_check(stacks, stacks->stack_a, stacks->len_a);
}