#include "../../includes/push_swap.h"

int	main(int argc, char *argv)
{
	t_stacks	*stacks;

	decide_input(stacks, argc, argv);
	sort_stacks(stacks);
}