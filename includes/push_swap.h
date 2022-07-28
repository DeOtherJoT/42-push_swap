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
void		process_input(t_stacks *stacks, int argc, char **argv);
void		fill_stacks(t_stacks *stacks, char **input, size_t len);
int			check_input(char *str);

// Input Utils
void		ft_put_error(void);
size_t		ft_arr_len(char **arr);

/* -.- Stacks Folder -.- */

// Stacks Init
t_stacks	*ft_stacks_new(size_t len);
void		ft_stacks_del(t_stacks *stacks);
int			ft_elem_get(int	*stack, int elem);
void		ft_elem_set(int *stack, int elem, int val);

/* -.- Sort Folder -.- */

// Operation 1
void		op_sa(t_stacks *stacks);
void		op_sb(t_stacks *stacks);
void		op_ss(t_stacks *stacks);
void		op_pa(t_stacks *stacks);
void		op_pb(t_stacks *stacks);

// Operation 2
void		op_ra(t_stacks *stacks);
void		op_rb(t_stacks *stacks);
void		op_rr(t_stacks *stacks);
void		op_rra(t_stacks *stacks);
void		op_rrb(t_stacks *stacks);

// Operation 3
void		op_rrr(t_stacks *stacks);

// Operation Utils
void		ft_shift_down(int *stack, size_t len);
void		ft_shift_up(int *stack, size_t len);

#endif