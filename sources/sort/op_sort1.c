#include "../../includes/push_swap.h"

void	op_sa(t_stacks *stacks)
{
	int	temp_0;

	if (stacks->len_a < 2)
		return ;
	temp_0 = ft_elem_get(stacks->stack_a, 0);
	ft_elem_set(stacks->stack_a, 0, ft_elem_get(stacks->stack_a, 1));
	ft_elem_set(stacks->stack_a, 1, temp_0);
}

void	op_sb(t_stacks *stacks)
{
	int	temp_0;

	if (stacks->len_b < 2)
		return ;
	temp_0 = ft_elem_get(stacks->stack_b, 0);
	ft_elem_set(stacks->stack_b, 0, ft_elem_get(stacks->stack_b, 1));
	ft_elem_set(stacks->stack_b, 1, temp_0);
}

void	op_ss(t_stacks *stacks)
{
	op_sa(stacks);
	op_sb(stacks);
}

void	op_pa(t_stacks *stacks)
{
	if (stacks->len_b == 0)
		return ;
	ft_shift_down(stacks->stack_a, stacks->len_a);
	ft_elem_set(stacks->stack_a, 0, ft_elem_get(stacks->stack_b, 0));
	ft_shift_up(stacks->stack_b, stacks->len_b);
	stacks->len_a += 1;
	stacks->len_b -= 1;
}

void	op_pb(t_stacks *stacks)
{
	if (stacks->stack_a == 0)
		return ;
	ft_shift_down(stacks->stack_b, stacks->len_b);
	ft_elem_set(stacks->stack_b, 0, ft_elem_get(stacks->stack_a, 0));
	ft_shift_up(stacks->stack_a, stacks->len_a);
	stacks->len_b += 1;
	stacks->len_a -= 1;
}