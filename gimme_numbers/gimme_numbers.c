/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gimme_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:57:37 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 22:58:01 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <time.h>

int	ft_in_arr(int val, int *arr, int curr)
{
	int	ctr;

	ctr = 0;
	while (ctr < curr)
	{
		if (val == arr[ctr])
			return (1);
		ctr++;
	}
	return (0);
}

int	get_rand(long lower, long upper, int *arr, int curr)
{
	long	ret;

	while (1 == 1)
	{
		ret = (rand() % (upper - lower + 1)) + lower;
		if (ft_in_arr(ret, arr, curr) == 0)
			break ;
	}
	return (ret);
}

int	*generate_rand_arr(int len)
{
	int	*int_arr;
	int	temp_gen;
	int	ctr;

	int_arr = ft_calloc(len, sizeof(int));
	ctr = 0;
	while (ctr < len)
	{
		temp_gen = get_rand(-2147483648, 0, int_arr, ctr);
		int_arr[ctr] = temp_gen;
		ctr++;
	}
	return (int_arr);
}

void	print_arr(int *arr, int len)
{
	int	ctr;

	ctr = 0;
	while (ctr < len)
	{
		ft_putnbr_fd(arr[ctr], 1);
		ft_putchar_fd(' ', 1);
		ctr++;
	}
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	int	len;
	int	*arr;

	if (argc != 2)
		exit(EXIT_SUCCESS);
	srand(time(0));
	len = ft_atoi(argv[1]);
	arr = generate_rand_arr(len);
	print_arr(arr, len);
	free(arr);
	return (0);
}
