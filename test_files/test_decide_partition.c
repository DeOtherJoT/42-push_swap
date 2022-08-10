#include "../includes/push_swap.h"

int	main(void)
{
	int		*limits;
	size_t	part_count;

	limits = decide_partitions(6, &part_count);
	printf("part_count : %zu\n", part_count);
	printf("limits : ");
	for (size_t i = 0; i < part_count; i++)
		printf("%d ", limits[i]);
	printf("\n");
}