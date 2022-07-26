#include "../../includes/push_swap.h"

/*
Decides the input type based on argc and adjusts the input accordingly.
No checks are done here, only done in fill_stacks().
*/

void	decide_input(t_stacks *stacks, int argc, char **argv)
{
	char	*temp_split;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
	{
		temp_split = ft_split(argv[1], ' ');
		fill_stacks(stacks, temp_split, ft_arr_len(temp_split));
		ft_free_array(temp_split);
	}
	else
	{
		fill_stacks(stacks, argv++, argc - 1);
	}
}

/*
Initialises the stacks and pushes the inputs to stack_a. Each number is
checked by ft_check_inpput. Exits the program with an error if it
encounters a bad input.
*/

void	fill_stacks(t_stacks *stacks, char **input, size_t len)
{
	size_t	i;

	stacks = ft_stacks_new(len);
	i = -1;
	while (++i < len)
		stacks->stack_a[i] = ft_check_input(input[i]);
}