/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:32:11 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:32:14 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Checks the input, str, for three things :-
	1. Are all the characters in str a digit?
		- digit_check()
	2. Is the number represented by str outside the int range?
		- limit_check()
	3. Is the number represented by str a duplicate?
		- dup_check()
If the answer is yes, an error is thrown and the program ends.
*/

int	check_input(char *str, int *stack, size_t current)
{
	int		conv_str;

	digit_check(str);
	conv_str = ft_atoi(str);
	limit_check(str, conv_str);
	dup_check(conv_str, stack, current);
	return (conv_str);
}

void	digit_check(char *str)
{
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	while (i < str_len)
	{
		if (ft_isdigit(str[i]) == 0)
			ft_put_error();
		i++;
	}
}

void	limit_check(char *str, int conv_str)
{
	char	*temp_str;

	temp_str = ft_itoa(conv_str);
	if (ft_strncmp(str, temp_str, ft_strlen(str)) != 0)
		ft_put_error();
	free(temp_str);
}

void	dup_check(int conv_str, int *stack, size_t current)
{
	size_t	i;

	i = 0;
	while (i < current)
	{
		if (conv_str == stack[i])
			ft_put_error();
		i++;
	}
}
