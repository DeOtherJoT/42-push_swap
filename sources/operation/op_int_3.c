#include "../../includes/push_swap.h"

/*
Executes the operations rra and rrb together as one operation.
*/

void	op_rrr(t_stacks *stacks)
{
	op_rra(stacks);
	op_rrb(stacks);
}