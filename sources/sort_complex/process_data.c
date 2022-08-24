#include "../../includes/push_swap.h"

int	get_target(int *stack, size_t len, int elem, int flag)
{
	size_t	ctr;
	int		ret;

	ctr = 0;
	ret = stack[0];
	if (flag == 0) //get the smallest in stack a
	{
		while (++ctr < len)
		{
			if (ret > stack[ctr])
				ret = stack[ctr];
		}
	}
	else // get the target above the elem
	{
		while (++ctr < len)
		{
			if (stack[ctr - 1] < elem && stack[ctr] > elem)
				ret = stack[ctr];
		}
	}
	return (ret);
}

void	get_moves_a(t_stacks *stacks, t_data *ret)
{
	size_t	x;
	int		target;

	if (ret->elem == (int)(stacks->len_a + stacks->len_b))
		target = get_target(stacks->stack_a, stacks->len_a, ret->elem, 0);
	else
		target = get_target(stacks->stack_a, stacks->len_a, ret->elem, 1);
	x = ft_elem_index(stacks->stack_a, target);
	ret->do_ra = x;
	ret->do_rra = stacks->len_a - x;
}

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