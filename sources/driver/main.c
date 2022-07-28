#include "../../includes/push_swap.h"

void	exit_prog(t_stacks *stacks)
{
	ft_stacks_del(stacks);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv)
{
	t_stacks	*stacks;

	process_input(stacks, argc, argv);
	sort_stacks(stacks);
	exit_prog(stacks);
}