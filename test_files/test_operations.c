#include "../includes/push_swap.h"

void	ft_print_stacks(t_stacks *stacks)
{
	size_t	counter = 0;
	// size_t	compare = stacks->len_a > stacks->len_b ? stacks->len_a : stacks->len_b;

	printf("len_a : %zu\nlen_b : %zu\n", stacks->len_a, stacks->len_b);
	printf("-------------------------\n");
	printf("A\t\t\tB\n");
	printf("-------------------------\n");
	while (counter < 10 /*compare*/)
	{
		printf("%d\t\t\t%d\n", stacks->stack_a[counter], stacks->stack_b[counter]);
		counter++;
	}
	printf("-------------------------\n");
}

int	main(void)
{
	// Create empty sstacks of len 10.
	t_stacks	*stacks = ft_stacks_new(10);
	int			i = 6;

	// Fill stack_a with 6 values, decreasing in this case.
	while (i > 0)
	{
		ft_elem_set(stacks->stack_a, 6 - i, i);
		i--;
	}
	// Manually set the length of stack_a as 6, we are using the remaining 4 spaces
	// to observe whether the operations work properly.
	stacks->len_a = 6;
	for (int i = 0; i < 2; i++)
	{
		op_ra(stacks);
		op_pb(stacks);
	}
	ft_print_stacks(stacks);
}