#include "../includes/push_swap.h"

int	get_target(int *stack, size_t len, int elem, int flag)
{
	size_t	ctr;
	int		ret;

	ctr = 0;
	ret = stack[0];
	if (flag == 0) //get the smallest in stack a
	{
		while (++ctr < len)
		{
			if (ret > stack[ctr])
				ret = stack[ctr];
		}
	}
	else // get the target above the elem
	{
		while (++ctr < len)
		{
			if (stack[ctr - 1] < elem && stack[ctr] > elem)
				ret = stack[ctr];
		}
	}
	return (ret);
}

int	main(void)
{
	int	stack[] = {2, 4, 5, 6};

	printf("returned target : %d\n", get_target(stack, 4, 3, 1));
}