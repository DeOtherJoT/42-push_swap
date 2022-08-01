#include "../../includes/push_swap.h"

int	ft_get_state(int *stack, size_t len)
{
	size_t	x;

	x = -1;
	if (len < 2)
		return (NO_ACT);
	if (stack[0] < stack[1])
	{
		while (++x < (len - 1))
		{
			if (stack[x] > stack[x + 1])
				return (UNSORTED);
		}
		return (SORTED_ASC);
	}
	else
	{
		while (++x < (len - 1))
		{
			if (stack[x] < stack[x + 1])
				return (UNSORTED);
		}
		return (SORTED_DES);
	}
}