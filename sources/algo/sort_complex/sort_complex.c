#include "../../../includes/push_swap.h"

/*
General idea :-
	1.	stack_a currently has all the unsorted indexed elements.
	2.	From len_a, split the stack into two, and push all elements in the
		lower half into stack_b, order does not matter for now.
	3.	For what remains in stack_a, repeat step 2.
	4.	Steps 2 - 3 are repeated until there are only the highest 3 or 2
		elements in stack_a. Sort using ft_sort_three() or op_ra if needed.
	5.	Now, the elements in stack_b are semi-sorted in their respective
		partitions. A sorting algorithm would be needed to push the largest
		element to stack_a iteratively until in the end, stack_a is sorted.

Sounds simple, but coding it would be a pain in the arse. Wish me luck.
*/

void	ft_sort_complex(t_stacks *stacks)
{
	int		*limits;
	size_t	part_count;

	limits = decide_partitions(stacks->len_a, &part_count);
	handle_partitions(stacks, limits, part_count);
	//begin_sort(stacks, limits);
	free(limits);
}

