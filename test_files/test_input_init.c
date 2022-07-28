#include "../includes/push_swap.h"
#include <limits.h>

void	test_check_input(void)
{
	const char	*val_arr[] = {"12", "0", "-42", "2147483647", "-2147483648", NULL};
	int			*val_check = {12, 0, -42, INT_MAX, INT_MIN};
	const char	*bad_arr[] = {"12x", "+1", "0 1 2", "2147483648", "-2147483649", NULL};

	int	i = 0;
	while (val_arr[i] != NULL)
	{
		if (check_input(val_arr[i]) != val_check[i])
			printf("check_input\t:\tKO!\n");
		i++;
	}
	i = 0;
	while (bad_arr[i] != NULL)
	{
		if (check_input(bad_arr[i]) != -1)
			printf("check_input\t:\tKO!\n");
		i++;
	}
	printf("check_input\t:\tSuccess!\n");
}

// void	test_process_input(void)
// {
// 	t_stacks	*stacks;

// 	process()
// }

int	main(void)
{
	test_check_input();
	//test_process_input();
	return (0);
}