#include "../../includes/push_swap.h"

void	smart_rotate(t_stacks *stacks)
{
	t_data	**list;
	size_t	i;

	list = malloc(sizeof(t_data *) * stacks->len_b);
	if (!list)
		err_msg("Error at t_data list creation.");
	i = 0;
	while (i < stacks->len_b);
	{
		list[i] = ft_data_new(stacks, i);
		i++;
	}
	complex_move(filter_list(list));
	ft_free_list(list);
}

void	begin_sort(t_stacks *stacks)
{
	// while (stacks->len_b != 0)
	// 	move_elem_b(stacks, (int)stacks->len_b);
	while (stacks->len_b != 0)
		smart_rotate(stacks);
}