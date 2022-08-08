#include "../../includes/push_swap.h"

void	ft_shift_down(int *stack, size_t len)
{
	while (len > 0)
	{
		ft_elem_set(stack, len, ft_elem_get(stack, len - 1));
		len--;
	}
	ft_elem_set(stack, 0, 0);
}

void	ft_shift_up(int *stack, size_t len)
{
	size_t	x;

	x = -1;
	while (++x < len - 1)
		ft_elem_set(stack, x, ft_elem_get(stack, x + 1));
	ft_elem_set(stack, x, 0);
}

void	ft_exec_op(t_stacks *stacks, char *op, void (*f)(t_stacks *))
{
	f(stacks);
	ft_putstr_fd(op, 1);
	ft_putchar_fd('\n', 1);
}