#include "../../../includes/push_swap.h"

/*
Returns the number of partitions intended to be in stack_b by iteratively
halving the total number of elements currently in stack_a.
*/

size_t	part_count(size_t len)
{
	int	ret;

	ret = 0;
	while (len >= 2)
	{
		len /= 2;
		ret++;
	}
	return (ret);
}

/*
Gets the number of partitions using part_count() and returns an array
of the upper limits of each partition.
These would be used to seperate each partition as the elements get
pushed from stack_a to stack_b.
*/

int	*decide_partitions(size_t len, size_t *partition_count)
{
	int		*ret;
	size_t	temp_val;
	size_t	temp_count;
	size_t	i;

	temp_count = part_count(len);
	ret = malloc(sizeof(int) * temp_count);
	i = -1;
	temp_val = 0;
	while (++i < temp_count)
	{
		len /= 2;
		temp_val += len;
		ret[i] = temp_val;
	}
	*partition_count = temp_count;
	return (ret);
}