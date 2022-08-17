#include "../../../includes/push_swap.h"

size_t	part_count(size_t len)
{
	size_t	ret;

	ret = (len / 20);
	if (len % 20 != 0)
		ret += 1;
	return (ret);
}

int	*decide_partitions(size_t len, size_t *partition_count)
{
	int		*ret;
	size_t	temp_count;
	size_t	i;

	temp_count = part_count(len);
	ret = malloc(sizeof(int) * temp_count);
	i = -1;
	while (++i < temp_count)
		ret[i] = (int)((i * 20) + 20);
	*partition_count = temp_count;
	return (ret);
}