#include "../includes/push_swap.h"

void	ft_print_stacks(t_stacks *stacks)
{
	size_t	counter = 0;

	printf("A\t\t\tB\n");
	while (counter < stacks->len_a)
	{
		printf("%d\t\t\t%d\n", stacks->stack_a[counter], stacks->stack_b[counter]);
		counter++;
	}
	printf("----------\n");
}

void	test_stack_functs(void)
{
	t_stacks	*stacks;
	size_t		counter_1 = 0;
	size_t		counter_2 = 0;

	stacks = ft_stacks_new(5);
	if (!stacks)
	{
		printf("ft_stack_init : KO!\n");
		exit(EXIT_FAILURE);
	}
	while (counter_1 < 5)
	{
		ft_elem_set(stacks->stack_b, counter_1, (int)(counter_1 + 1));
		counter_1++;
	}
	while (counter_2 < 5)
	{
		if (ft_elem_get(stacks->stack_a, counter_2) != 0)
		{
			printf("ft_elem_get : KO!\n");
			exit(EXIT_FAILURE);
		}
		if (stacks->stack_b[counter_2] != (int)(counter_2 + 1))
		{
			printf("ft_elem_set : KO!\n");
			exit(EXIT_FAILURE);
		}
		counter_2++;
	}
	printf("stack_functs : OK!\n");
	ft_stacks_del(stacks);
}

int	main(void)
{
	test_stack_functs();
	return (1);
}