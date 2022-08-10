#include "../../includes/push_swap.h"

void	ft_print_stacks(t_stacks *stacks)
{
	size_t	counter = 0;
	size_t	compare = stacks->len_a > stacks->len_b ? stacks->len_a : stacks->len_b;

	printf("A\t\t\tB\n");
	printf("-------------------------\n");
	while (counter < compare)
	{
		printf("%d\t\t\t%d\n", stacks->stack_a[counter], stacks->stack_b[counter]);
		counter++;
	}
	printf("-------------------------\n");
}

void	exit_prog(t_stacks *stacks)
{
	ft_stacks_del(stacks);
	system("leaks push_swap"); //
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = process_input(argc, argv);
	sort_stacks(stacks);
	ft_print_stacks(stacks); //
	exit_prog(stacks);
}