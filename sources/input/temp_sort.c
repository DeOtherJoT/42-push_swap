/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:32:40 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:32:44 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Helper function that swaps the two integers passed by reference.
*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
Partition function that sorts values with respect to the rightmost
element in the partition, returns a pivot element.
*/

size_t	partition(int *arr, int low, int high)
{
	int		pivot;
	int		i;

	pivot = arr[high];
	i = (int)low - 1;
	while (low < high)
	{
		if (arr[low] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[low]);
		}
		low++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/*
Temporary sorter that uses the quicksort algorithm to sort the
temp_stack.
*/

void	temp_sort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		temp_sort(arr, low, pivot - 1);
		temp_sort(arr, pivot + 1, high);
	}
}
