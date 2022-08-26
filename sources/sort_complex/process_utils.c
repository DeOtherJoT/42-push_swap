/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:34:37 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:34:38 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Checks whether the parameter elem is either the smallest value or the largest
value in stack_a.
*/

int	ft_isborder(int elem, int *stack_a, size_t len_a)
{
	size_t	ctr;

	ctr = 0;
	if (elem < stack_a[0])
	{
		while (ctr < len_a)
		{
			if (elem > stack_a[ctr])
				return (-1);
			ctr++;
		}
	}
	else
	{
		while (ctr < len_a)
		{
			if (elem < stack_a[ctr])
				return (-1);
			ctr++;
		}
	}
	return (1);
}

/*
Returns the size of the partitions based off of the total number of elements
passed in.
*/

int	ft_getfactor(size_t len)
{
	if (len < 20)
		return (10);
	if (len < 200)
		return (20);
	else
		return (50);
}
