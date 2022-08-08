#include "../includes/push_swap.h"
#include <limits.h>

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

void	test_process_input_str(void)
{
	t_stacks	*stack;
	//char		*str[] = {"./push_swap", "1", "42", "200", "-2147483648", "-10"};
	char		*str2[] = {"./push_swap", "1 42 -60 200 -2147483648 -10 0 22x2"};

	stack = process_input(2, str2);
	ft_print_stacks(stack);
	return ;
}

int	main(void)
{
	test_process_input_str();
	return (0);
}