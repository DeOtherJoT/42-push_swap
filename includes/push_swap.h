#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define UNSORTED -1
# define NO_ACT 0
# define SORTED_ASC 1
# define SORTED_DES 2

# include "../libft/libft.h"

typedef struct s_stacks
{
	size_t	len_a;
	size_t	len_b;
	int		*stack_a;
	int		*stack_b;
	size_t	moves;
}	t_stacks;

typedef	struct s_data
{
	int		elem;
	size_t	do_ra;
	size_t	do_rra;
	size_t	do_rb;
	size_t	do_rrb;
	size_t	do_rr;
	size_t	do_rrr;
	size_t	total_moves;
}	t_data;


/* -.- Driver Folder -.- */

// Main
void		exit_prog(t_stacks *stacks);
void		ft_print_stacks(t_stacks *stacks);

/* -.- Input Folder -.- */

// Process Input
t_stacks	*process_input(int argc, char **argv, size_t *elem_num);
t_stacks	*fill_stacks(char **input, size_t len);
void		index_stack(int *stack, int *sorted_arr, size_t len);
int			binary_search(int *array, size_t first, size_t last, int val);

// Check Input
int			check_input(char *str, int *stack, size_t current);
void		digit_check(char *str);
void		limit_check(char *str, int conv_str);
void		dup_check(int conv_str, int *stack, size_t current);

// Temp Sort (Quick Sort Algo)
void		temp_sort(int *arr, int low, int high);
size_t		partition(int *arr, int low, int high);
void		ft_swap(int *a, int *b);

// Input Utils
void		ft_put_error(void);
size_t		ft_arr_len(char **arr);

/* -.- Stacks Folder -.- */

// Stacks Init
t_stacks	*ft_stacks_new(size_t len);
void		ft_stacks_del(t_stacks *stacks);
int			ft_elem_get(int	*stack, int elem);
void		ft_elem_set(int *stack, int elem, int val);

/* -.- Sort Simple -.- */

// Sort Stacks
void		sort_stacks(t_stacks *stacks);
void		first_check(t_stacks *stacks, int *stack, size_t len);

// Sort Simple
void		ft_sort_three(t_stacks *stacks, int *stack, size_t len);
void		ft_sort_simple(t_stacks *stacks);

// Sort Utils
int			ft_get_state(int *stack, size_t len);

/* Sort Complex New */

// Sort Complex
void		ft_sort_complex(t_stacks *stacks);
void		push_partition(t_stacks *stacks, int limit);
int			*get_limits(size_t len, size_t *part_count);
void		decide_push(t_stacks *stacks, int top, int bottom);

// Begin Sort
void		begin_sort(t_stacks *stacks);

/* Sort Complex OLD

void		ft_sort_complex(t_stacks *stacks);
void		begin_sort(t_stacks *stacks);

// Decide Partition
size_t		part_count(size_t len);
int			*decide_partitions(size_t len, size_t *partition_count);

// Push Partition
void		push_partitions(t_stacks *stacks, int limit);
void		handle_partitions(t_stacks *stacks, int *limits, size_t part_cnt);
*/


/* -.- Operation Folder -.- */

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
void		ft_exec_op(t_stacks *stacks, char *op, void (*f)(t_stacks *));

// Move Elements
void		move_elem_a(t_stacks *stacks, int elem);
size_t		ft_elem_index(int *src, int elem);
void		move_elem_b(t_stacks *stacks, int elem);

#endif