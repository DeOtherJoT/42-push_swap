#include "../../includes/push_swap.h"

void	decide_push(t_stacks *stacks, int top, int bottom)
{
	size_t	move_top;
	size_t	move_bottom;

	if (top == bottom)
	{
		move_elem_a(stacks, top);
		return ;
	}
	move_top = ft_elem_index(stacks->stack_a, top);
	move_bottom = stacks->len_a - ft_elem_index(stacks->stack_a, bottom);
	if (move_top == move_bottom)
	{
		if (top > bottom)
			move_elem_a(stacks, bottom);
		else
			move_elem_a(stacks, top);
	}
	else if (move_top > move_bottom)
		move_elem_a(stacks, bottom);
	else
		move_elem_a(stacks, top);
}