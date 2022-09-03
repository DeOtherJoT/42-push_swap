/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:35:44 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:36:07 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Returns a new instance of the t_stacks type, with the variables initialised
to 0. Both stacks are intialised to the input length.
*/

t_stacks	*ft_stacks_new(size_t len)
{
	t_stacks	*ret;

	ret = malloc(sizeof(t_stacks));
	ret->stack_a = ft_calloc(len, sizeof(int));
	ret->stack_b = ft_calloc(len, sizeof(int));
	ret->len_a = len;
	ret->len_b = 0;
	return (ret);
}

/*
Deletes the t_stacks instance passed as the parameter.
*/

void	ft_stacks_del(t_stacks *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}

/*
Returns the element that is referenced by the parameter index
in the passed stack.
*/

int	ft_elem_get(int	*stack, int index)
{
	return (stack[index]);
}

/*
Sets the value of the location in the stack referenced by index.
*/

void	ft_elem_set(int *stack, int index, int val)
{
	stack[index] = val;
}
