/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:12:56 by jthor             #+#    #+#             */
/*   Updated: 2022/09/03 14:13:25 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

/*
Exit function for bonus implementation, wheere there are 2 possible outcomes
OK or KO.
*/

void	exit_bonus(t_stacks *stacks, int flag)
{
	if (flag == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_stacks_del(stacks);
	exit(EXIT_SUCCESS);
}

/*
Returns the index of the correct function to be executed in the array of
function pointers. Messy if-else implementation, but I'm too lazy to think
of other methods.
*/

int	get_op_index(char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		return (0);
	else if (ft_strncmp(op, "sb", 2) == 0)
		return (1);
	else if (ft_strncmp(op, "ss", 2) == 0)
		return (2);
	else if (ft_strncmp(op, "pa", 2) == 0)
		return (3);
	else if (ft_strncmp(op, "pb", 2) == 0)
		return (4);
	else if (ft_strncmp(op, "ra", 2) == 0)
		return (5);
	else if (ft_strncmp(op, "rb", 2) == 0)
		return (6);
	else if (ft_strncmp(op, "rra", 3) == 0)
		return (8);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		return (9);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		return (10);
	else if (ft_strncmp(op, "rr", 2) == 0)
		return (7);
	else
		return (-1);
}

/*
Executes the received instruction using an arrray of function pointers.
*/

void	exec_inst(t_stacks *stacks, void (*op_arr[11]) (t_stacks *), char *op)
{
	int	index;

	index = get_op_index(op);
	if (index == -1)
		return ;
	op_arr[index](stacks);
}

/*
Initialises the array of function pointers.
*/

void	init_op_arr(void (*op_arr[11]) (t_stacks *))
{
	op_arr[0] = op_sa;
	op_arr[1] = op_sb;
	op_arr[2] = op_ss;
	op_arr[3] = op_pa;
	op_arr[4] = op_pb;
	op_arr[5] = op_ra;
	op_arr[6] = op_rb;
	op_arr[7] = op_rr;
	op_arr[8] = op_rra;
	op_arr[9] = op_rrb;
	op_arr[10] = op_rrr;
}

/*
Uses the same input processing as the main push_swap program, and once the
push_swap program is done, the output is piped to this program. This program
will then execute each instruction line by line until it reaches the EOF,
where it will check if
	1. All elements are in stack_a, and no elements are duplicated.
	2. The elements are sorted in ascending order.
Depending on the results, the checker program exits accordingly.
*/

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	void		(*op_arr[11])(t_stacks *);
	size_t		elem_num;
	void		*temp_ins;

	stacks = process_input(argc, argv);
	init_op_arr(op_arr);
	elem_num = stacks->len_a;
	temp_ins = get_next_line(STDIN_FILENO);
	while (temp_ins)
	{
		exec_inst(stacks, op_arr, temp_ins);
		free(temp_ins);
		temp_ins = get_next_line(STDIN_FILENO);
	}
	if (stacks->len_a != elem_num || stacks->len_b != 0)
		exit_bonus(stacks, 1);
	if (ft_get_state(stacks->stack_a, stacks->len_a) != SORTED_ASC)
		exit_bonus(stacks, 1);
	exit_bonus(stacks, 0);
}
