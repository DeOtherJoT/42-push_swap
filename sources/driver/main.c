/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:31:35 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:31:55 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	exit_prog(t_stacks *stacks)
{
	ft_stacks_del(stacks);
	system("leaks push_swap");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	size_t		elem_num;

	stacks = process_input(argc, argv, &elem_num);
	sort_stacks(stacks);
	ft_mini_checker(stacks, elem_num);
	exit_prog(stacks);
}
