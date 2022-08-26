#include "../../includes/push_swap.h"

int	ft_isborder(int elem, int *stack_a, size_t len_a)
{
	size_t	ctr;

	ctr = 0;
	if (elem < stack_a[0])
	{
		// check if elem is the smallest in stack_a
		while (ctr < len_a)
		{
			if (elem > stack_a[ctr])
				return (-1);
			ctr++;
		}
	}
	else
	{
		// check if elem is the largest in stack_a
		while (ctr < len_a)
		{
			if (elem < stack_a[ctr])
				return (-1);
			ctr++;
		}
	}
	return (1);
}