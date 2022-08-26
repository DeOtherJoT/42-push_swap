/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ins_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:33:48 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:33:50 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Executes the operations rra and rrb together as one operation.
*/

void	op_rrr(t_stacks *stacks)
{
	op_rra(stacks);
	op_rrb(stacks);
}
