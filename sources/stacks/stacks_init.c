#include "../../includes/push_swap.h"

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

void	ft_stacks_del(t_stacks *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}

int	ft_elem_get(int	*stack, int elem)
{
	return(stack[elem]);
}

void	ft_elem_set(int *stack, int elem, int val)
{
	stack[elem] = val;
}