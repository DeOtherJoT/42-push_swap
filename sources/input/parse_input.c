/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:27:36 by jthor             #+#    #+#             */
/*   Updated: 2023/03/21 13:27:39 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
In the case that the input is multiple strings, this function is called to
handle it, so inputs such as :
	[i]  ./push_swap 1 3 2 4
	[ii] ./push_swap 1 3 "2 4"

First, check through all strings and make sure there are no empty strings, "".
Then, combine all the individual strings in order to handle case [ii].
Finally, split them again, this time with respect to whitespaces and call
fill_stacks(), and the program continues from there.
*/

t_stacks	*parse_extra(char **argv, int argc)
{
	int			i;
	char		*temp_merge;
	char		**final_arr;
	t_stacks	*ret;

	i = -1;
	while (++i < argc)
	{
		if (argv[i][0] == '\0')
			ft_put_error();
	}
	temp_merge = combine_strings(argv, argc);
	final_arr = ft_split_alt(temp_merge, " \t\n\v\f\r");
	ret = fill_stacks(final_arr, ft_arr_len(final_arr));
	ft_free_array(final_arr);
	return (ret);
}

/*
Combines multiple strings to a single string, in the order of input.
Returns a new string, no updates are applied to the original parameter.
*/

char	*combine_strings(char **argv, int argc)
{
	int		i;
	char	*ret;
	char	*temp_ret;
	char	*temp_str;

	i = 1;
	ret = ft_strdup(argv[0]);
	while (i < argc)
	{
		temp_str = ft_strjoin(" ", argv[i]);
		temp_ret = ft_strjoin(ret, temp_str);
		free(ret);
		ret = temp_ret;
		i++;
		free(temp_str);
	}
	return (ret);
}
