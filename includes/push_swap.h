#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stacks
{
	size_t	len_a;
	size_t	len_b;
	int		*stack_a;
	int		*stack_b;
}	t_stacks;

/* -.- Driver Folder -.- */

// Decide Input
void		decide_input(t_stacks *stacks, int argc, char **argv);
void		fill_stacks(t_stacks *stacks, char **input, size_t len);

// Input Utils
void		ft_put_error(void);

/* -.- Stacks Folder -.- */

// Stacks Init
t_stacks	*ft_stacks_new(size_t len);
void		ft_stacks_del(t_stacks *stacks);
#endif