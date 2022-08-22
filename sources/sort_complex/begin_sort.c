#include "../../includes/push_swap.h"

void	smart_rotate(t_stacks *stacks)
{
	t_pslist	*head;
	t_pslist	*temp;
	size_t		i;

	i = 0;
	head = ft_pslistnew(get_move_a(stacks, i), get_move_b(stacks, i));
	i++;
	while (i < stacks->len_b)
	{
		temp = ft_pslistnew(get_move_a(stacks, i), get_move_b(stacks, i));
		i++;
	}
}

void	begin_sort(t_stacks *stacks)
{
	// while (stacks->len_b != 0)
	// 	move_elem_b(stacks, (int)stacks->len_b);
	while (stacks->len_b != 0)
		smart_rotate(stacks);
}