#include "../../includes/push_swap.h"

/*
Decides the input type based on argc and adjusts the input accordingly.
No checks are done here, only done in fill_stacks().
*/

void	process_input(t_stacks *stacks, int argc, char **argv)
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
checked by check_input.
*/

void	fill_stacks(t_stacks *stacks, char **input, size_t len)
{
	size_t	i;

	stacks = ft_stacks_new(len);
	i = -1;
	while (++i < len)
		stacks->stack_a[i] = check_input(input[i], stacks->stack_a, i);
}

/*
Checks the input, str, for three things :-
	1. Are all the characters in str a digit?
	2. Is the number represented by str outside the int range?
	3. Is the number represented by str a duplicate?
If the answer is yes, an error is thrown and the program ends.
*/

int	check_input(char *str, int *stack, size_t current)
{
	int		temp_int;
	char	*temp_str;
	size_t	str_len;
	size_t	i;

	i = -1;
	str_len = ft_strlen(str);
	while (++i < str_len)
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1); // ft_put_error();
	}
	temp_int = ft_atoi(str);
	temp_str = ft_itoa(str);
	if (ft_strncmp(str, temp_str, str_len) != 0)
		return (-1); // ft_put_error();
	free(temp_str);
	i = -1;
	while (++i < current)
	{
		if (temp_int == stack[i])
			return (-1); // ft_put_error();
	}
	return (temp_int);
}