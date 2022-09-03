/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:12:34 by jthor             #+#    #+#             */
/*   Updated: 2022/09/03 14:12:36 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Exits the program, needs it's own file because I do not include the main.c
file in the object file creation.
*/

void	exit_prog(t_stacks *stacks)
{
	ft_stacks_del(stacks);
	exit(EXIT_SUCCESS);
}

/*
Checks the stack and returns if the stack is either
	A) Unsorted
	B) Sorted in Descending order
	C) Sorted in Ascending order
*/

int	ft_get_state(int *stack, size_t len)
{
	size_t	x;

	x = -1;
	if (len < 2)
		return (NO_ACT);
	if (stack[0] > stack[1])
	{
		while (++x < (len - 1))
		{
			if (stack[x] < stack[x + 1])
				return (UNSORTED);
		}
		return (SORTED_DES);
	}
	else
	{
		while (++x < (len - 1))
		{
			if (stack[x] > stack[x + 1])
				return (UNSORTED);
		}
		return (SORTED_ASC);
	}
}