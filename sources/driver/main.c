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

	stacks = process_input(argc, argv);
	sort_stacks(stacks);
	exit_prog(stacks);
}
