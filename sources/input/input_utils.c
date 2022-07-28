#include "../../includes/push_swap.h"

size_t	ft_arr_len(char **arr)
{
	size_t	ret;

	ret = 0;
	while (arr[ret] != NULL)
		ret++;
	return (ret);
}

void	ft_put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}