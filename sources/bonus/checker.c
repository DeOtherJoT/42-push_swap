#include "../../includes/checker.h"

void	exit_bonus(t_stacks *stacks, int flag)
{
	if (flag == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_stacks_del(stacks);
	exit(EXIT_SUCCESS);
}

void	exec_inst(t_stacks *stacks, char *ins)
{
	
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	void		(*op_arr) ();
	size_t		elem_num;
	char		*temp_ins;

	stacks = process_input(argc, argv, &elem_num);
	while (1 == 1)
	{
		temp_ins = get_next_line(STDOUT_FILENO);
		if (temp_ins == '/0')
			break;
		exec_inst(stacks, temp_ins);
		free(temp_ins);
	}
	if (stacks->len_a != elem_num || stacks->len_b != 0)
		exit_bonus(stacks, 1);
	if (ft_get_state(stacks->stack_a, stacks->len_a) != SORTED_ASC)
		exit_bonus(stacks, 1);
	exit_bonus(stacks, 0);
}