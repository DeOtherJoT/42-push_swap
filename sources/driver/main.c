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
	//system("leaks push_swap"); //
	exit(EXIT_SUCCESS);
}

/*
Fast checker to check basic shit. This is assuming that the stacks are
initialised correctly.
*/

void	ft_mini_checker(t_stacks *stacks, size_t elem_num)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	printf("Moves done : %zu\n", stacks->moves);
	ft_print_stacks(stacks);
	if (stacks->len_b != 0)
		flag = printf("KO : len_b != 0\n");
	if (stacks->len_a != elem_num)
		flag = printf("KO : len_a != elem_num\n");
	if (ft_get_state(stacks->stack_a, stacks->len_a) != SORTED_ASC)
	{
		flag = printf("KO : stack_a not sorted\n");
		while (i < (int)stacks->len_a)
		{
			if ((i + 1) != stacks->stack_a[i])
			{
				printf("Unsorted element is : %d\n", stacks->stack_a[i]);
				break ;
			}
			i++;
		}
	}
	if (flag == 0)
	{
		printf("Success!\n");
		printf("%zu elements have been sorted in %zu moves!\n", stacks->len_a, stacks->moves);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	size_t		elem_num;

	stacks = process_input(argc, argv, &elem_num);
	sort_stacks(stacks);
	ft_mini_checker(stacks, elem_num);
	exit_prog(stacks);
}