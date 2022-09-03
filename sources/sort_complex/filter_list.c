/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:24:29 by jthor             #+#    #+#             */
/*   Updated: 2022/09/03 20:24:32 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Looks for the element that would be pushed with the least amount of moves.
If there are multiple, filter again, this time taking into account the
highest occurence of rr or rrr.
*/

t_data	*filter_list(t_data **list, size_t len)
{
	size_t	ctr;
	size_t	flag_ctr;
	int		temp_total;

	ctr = 0;
	temp_total = list[ctr]->total_moves;
	while (++ctr < len)
	{
		if (temp_total > list[ctr]->total_moves)
			temp_total = list[ctr]->total_moves;
	}
	ctr = -1;
	flag_ctr = 0;
	while (++ctr < len)
	{
		if (list[ctr]->total_moves == temp_total)
		{
			flag_ctr++;
			list[ctr]->flag = 1;
		}
	}
	return (filter_list2(list, len, flag_ctr));
}

t_data	*filter_list2(t_data **list, size_t len, size_t flag_ctr)
{
	if (flag_ctr == 1)
		return (filter_one(list, len));
	else
		return (filter_two(list, len));
}

t_data	*filter_one(t_data **list, size_t len)
{
	size_t	ctr;

	ctr = -1;
	while (++ctr < len)
	{
		if (list[ctr]->flag == 1)
			return (list[ctr]);
	}
	return (list[ctr]);
}

t_data	*filter_two(t_data **list, size_t len)
{
	size_t	ctr;
	size_t	index;
	size_t	temp_total;

	ctr = -1;
	temp_total = 0;
	while (++ctr < len)
	{
		if (list[ctr]->flag == 1)
		{
			if (temp_total == 0
				|| (int)temp_total > (list[ctr]->do_rrr + list[ctr]->do_rr))
			{
				temp_total = list[ctr]->do_rrr + list[ctr]->do_rr;
				index = ctr;
			}
		}
	}
	return (list[index]);
}
