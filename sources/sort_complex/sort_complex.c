#include "../../includes/push_swap.h"

/*
Initialises an array and populates it with the limits of each partition,
Each of them being a multiple of 20 until the last element.
*/

int		*get_limits(size_t len, size_t *part_count)
{
	int		*ret;
	size_t	i;

	*part_count = len / 20;
	if ((len % 20) != 0)
		*part_count += 1;
	ret = malloc(sizeof(int) * (*part_count));
	i = -1;
	while (++i < (len / 20))
		ret[i] = (i * 20) + 20;
	if (len % 20 != 0)
		ret[i] = (i * 20) + (len % 20);
	return (ret);
}

void	decide_push(t_stacks *stacks, int top, int bottom)
{
	size_t	move_top;
	size_t	move_bottom;

	if (top == bottom)
	{
		move_elem_a(stacks, top);
		return ;
	}
	move_top = ft_elem_index(stacks->stack_a, top);
	move_bottom = stacks->len_a - ft_elem_index(stacks->stack_a, bottom);
	if (move_top == move_bottom)
	{
		if (top > bottom)
			move_elem_a(stacks, bottom);
		else
			move_elem_a(stacks, top);
	}
	else if (move_top > move_bottom)
		move_elem_a(stacks, bottom);
	else
		move_elem_a(stacks, top);
}

/*
Pushes each partition to stack_b in descending order. The last partition will have a
special condition, where two elements must remain in stack_a for the sorting
algorithm to actually work.
*/

void	push_partition(t_stacks *stacks, int limit)
{
	size_t	x;
	int		top;
	int		bottom;

	while ((int)(stacks->len_b) != limit && stacks->len_a > 2)
	{
		x = 0;
		while (stacks->stack_a[x] > limit)
			x++;
		top = stacks->stack_a[x];
		x = 0;
		while (stacks->stack_a[stacks->len_a - 1 - (x)] > limit)
			x++;
		bottom = stacks->stack_a[stacks->len_a - 1 - (x)];
		decide_push(stacks, top, bottom);
	}
}

/*
Sorting algorithm for more than 5 elements, divided into partitions that
take at most 20 elements.
*/

void	ft_sort_complex(t_stacks *stacks)
{
	size_t	part_count;
	size_t	i;
	int		*limits;

	limits = get_limits(stacks->len_a, &part_count);
	i = -1;
	while (++i < part_count)
		push_partition(stacks, limits[i]);
	begin_sort(stacks/*, limits, part_count*/);
	free(limits);
}