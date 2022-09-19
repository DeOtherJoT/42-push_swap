#include "../../includes/push_swap.h"

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
	final_arr = ft_split(temp_merge, ' ');
	ret = fill_stacks(final_arr, ft_arr_len(final_arr));
	ft_free_array(final_arr);
	return (ret);
}

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