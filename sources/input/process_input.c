#include "../../includes/push_swap.h"

/*
Decides the input type based on argc and adjusts the input accordingly.
No checks are done here, only done in fill_stacks() by check_input().
*/

t_stacks	*process_input(int argc, char **argv, size_t *elem_num)
{
	char		**temp_split;
	t_stacks	*ret;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
	{
		temp_split = ft_split(argv[1], ' ');
		*elem_num = ft_arr_len(temp_split);
		ret = fill_stacks(temp_split, *elem_num);
		ft_free_array(temp_split);
	}
	else
	{
		*elem_num = argc - 1;
		ret = fill_stacks(argv + 1, argc - 1);
	}
	return (ret);
}

/*
Initialises the stacks and pushes the inputs to stack_a. Each number is
checked by check_input().
*/

t_stacks	*fill_stacks(char **input, size_t len)
{
	size_t		i;
	t_stacks	*stacks;
	int			*temp_stack;

	stacks = ft_stacks_new(len);
	i = -1;
	while (++i < len)
		stacks->stack_a[i] = check_input(input[i], stacks->stack_a, i);
	temp_stack = malloc(len * sizeof(int));
	ft_memcpy(temp_stack, stacks->stack_a, len * sizeof(int));
	temp_sort(temp_stack, 0, len - 1);
	index_stack(stacks->stack_a, temp_stack, len);
	free(temp_stack);
	return (stacks);
}

/*
Checks every element in stack against its position in the sorted_arr.
The element is then replaced with the corresponding index + 1.
For example :-

BEFORE
stack      = [35, 11, 24, 65, 34]
sorted_arr = [11, 24, 34, 35, 65]
index + 1      1   2   3   4   5

AFTER
stack = [4, 1, 2, 5, 3]
*/

void	index_stack(int *stack, int *sorted_arr, size_t len)
{
	int		index;
	size_t	counter;

	counter = 0;
	while (counter < len)
	{
		index = binary_search(sorted_arr, 0, len - 1, stack[counter]);
		if (index == -1)
			ft_put_error();
		stack[counter] = index + 1;
		counter++;
	}
}

/*
Common binary search algorithm that returns the index of an element
in a sorted array.
*/

int	binary_search(int *array, size_t first, size_t last, int val)
{
	int	mid;

	mid = -1;
	if (last >= first)
	{
		mid = first + ((last - first) / 2);
		if (array[mid] == val)
			return (mid);
		if (array[mid] > val)
			return (binary_search(array, first, mid - 1, val));
		return (binary_search(array, mid + 1, last, val));
	}
	return (mid);
}