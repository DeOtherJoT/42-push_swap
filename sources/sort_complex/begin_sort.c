#include "../../includes/push_swap.h"

void	ft_print_data(t_data *node)
{
	printf("---------------\n");
	printf("elem   : %d\n", node->elem);
	printf("do_ra  : %d\n", node->do_ra);
	printf("do_rb  : %d\n", node->do_rb);
	printf("do_rra : %d\n", node->do_rra);
	printf("do_rrb : %d\n", node->do_rrb);
	printf("do_rr  : %d\n", node->do_rr);
	printf("do_rrr : %d\n", node->do_rrr);
	printf("tmoves : %d\n", node->total_moves);
	printf("---------------\n");
}

t_data	*filter_list(t_data **list, size_t len)
{
	size_t	ctr;
	int		temp_total;
	size_t	temp_index;

	ctr = 0;
	temp_index = 0;
	temp_total = list[ctr]->total_moves;
	while (++ctr < len)
	{
		if (temp_total > list[ctr]->total_moves)
		{
			temp_total = list[ctr]->total_moves;
			temp_index = ctr;
		}
	}
	//printf("%zu\n", temp_index);
	//ft_print_data(list[temp_index]);
	return (list[temp_index]);
}

void	complex_move(t_stacks *stacks, t_data *ins)
{
	while ((ins->do_ra)-- > 0)
		ft_exec_op(stacks, "ra", op_ra);
	while ((ins->do_rb)-- > 0)
		ft_exec_op(stacks, "rb", op_rb);
	while ((ins->do_rr)-- > 0)
		ft_exec_op(stacks, "rr", op_rr);
	while ((ins->do_rra)-- > 0)
		ft_exec_op(stacks, "rra", op_rra);
	while ((ins->do_rrb)-- > 0)
		ft_exec_op(stacks, "rrb", op_rrb);
	while ((ins->do_rrr)-- > 0)
	{
		//printf("%d\n", ins->do_rrr);
		ft_exec_op(stacks, "rrr", op_rrr);
	}
	ft_exec_op(stacks, "pa", op_pa);
}

void	ft_free_list(t_data **list, size_t len)
{
	size_t	ctr;

	ctr = -1;
	while (++ctr < len)
		free(list[ctr]);
	free(list);
}

void	smart_rotate(t_stacks *stacks)
{
	t_data	**list;
	size_t	i;

	list = malloc(sizeof(t_data *) * stacks->len_b);
	if (!list)
		err_msg("Error at t_data list creation.");
	i = 0;
	while (i < stacks->len_b)
	{
		list[i] = ft_data_new(stacks, i);
		ft_print_data(list[i]);
		i++;
	}
	//ft_put_error();
	complex_move(stacks, filter_list(list, stacks->len_b));
	ft_print_stacks(stacks);
	ft_free_list(list, stacks->len_b + 1);
}

void	begin_sort(t_stacks *stacks)
{
	// while (stacks->len_b != 0)
	// 	move_elem_b(stacks, (int)stacks->len_b);
	//ft_print_stacks(stacks);
	while (stacks->len_b != 0)
		smart_rotate(stacks);
}