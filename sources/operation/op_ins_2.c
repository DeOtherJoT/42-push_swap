#include "../../includes/push_swap.h"

void	op_ra(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_a < 2)
		return ;
	temp = ft_elem_get(stacks->stack_a, 0);
	ft_shift_up(stacks->stack_a, stacks->len_a);
	ft_elem_set(stacks->stack_a, stacks->len_a - 1, temp);
}

void	op_rb(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_b < 2)
		return ;
	temp = ft_elem_get(stacks->stack_b, 0);
	ft_shift_up(stacks->stack_b, stacks->len_b);
	ft_elem_set(stacks->stack_b, stacks->len_b - 1, temp);
}

void	op_rr(t_stacks *stacks)
{
	op_ra(stacks);
	op_rb(stacks);
}

void	op_rra(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_a < 2)
		return ;
	temp = ft_elem_get(stacks->stack_a, stacks->len_a - 1);
	ft_shift_down(stacks->stack_a, stacks->len_a);
	ft_elem_set(stacks->stack_a, 0, temp);
}

void	op_rrb(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_b < 2)
		return ;
	temp = ft_elem_get(stacks->stack_b, stacks->len_b - 1);
	ft_shift_down(stacks->stack_b, stacks->len_b);
	ft_elem_set(stacks->stack_b, 0, temp);
}