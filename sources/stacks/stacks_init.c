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

t_stacks	*ft_stacks_new(size_t len)
{
	t_stacks	*ret;

	ret = malloc(sizeof(t_stacks));
	ret->stack_a = ft_calloc(len, sizeof(int));
	ret->stack_b = ft_calloc(len, sizeof(int));
	ret->len_a = len;
	ret->len_b = 0;
	ret->moves = 0;
	return (ret);
}

void	ft_stacks_del(t_stacks *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}

int	ft_elem_get(int	*stack, int elem)
{
	return (stack[elem]);
}

void	ft_elem_set(int *stack, int elem, int val)
{
	stack[elem] = val;
}
