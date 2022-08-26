#EXEC NAME#

NAME		= push_swap
GIMME_NUM	= gimme_numbr

#FLAGS#

GCC			= gcc -Wall -Wextra -Werror
FSAN		= -fsanitize=address -g
RM			= rm -rf

#PATH LIB#

LIBFT		= libft
INC			= -Iinclude -I$(LIBFT)
LIB			= -L$(LIBFT) libft/libft.a
SRC_DIR		= sources/
SIM_DIR		= $(SRC_DIR)sort_simple/
DRV_DIR		= $(SRC_DIR)driver/
INP_DIR		= $(SRC_DIR)input/
OPR_DIR		= $(SRC_DIR)operation/
STK_DIR		= $(SRC_DIR)stacks/
CPLX_DIR	= $(SRC_DIR)sort_complex/
JFF_DIR		= gimme_numbers/
MAIN		= $(DRV_DIR)main.c

#SOURCE FILES#

SRCS		= $(addprefix $(SIM_DIR), sort_stacks.c sort_simple.c sort_utils.c) \
			  $(addprefix $(INP_DIR), check_input.c input_utils.c process_input.c temp_sort.c) \
			  $(addprefix $(OPR_DIR), move_elem.c op_ins_1.c op_ins_2.c op_ins_3.c op_utils.c) \
			  $(addprefix $(STK_DIR), stacks_init.c) \
			  $(addprefix $(CPLX_DIR), sort_complex.c begin_sort.c process_data.c process_helper.c process_utils.c)
JFF_SRCS	= $(addprefix $(JFF_DIR), gimme_numbers.c)
OBJS		= $(SRCS:.c=.o)

#RECIPES#

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(MAKE) all -C $(LIBFT)
	$(GCC) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB)

%.o		: %.c
	$(GCC) $(INC) -c $< -o $@

clean	:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT)

fclean	: clean
	$(RM) $(NAME) $(GIMME_NUM)
	$(RM) push_swap.dSYM gimme_numbr.dSYM
	$(MAKE) fclean -C $(LIBFT);

norm	:
	norminette $(SRC_DIR)
	norminette includes/push_swap.h

fsan	: fclean $(OBJS)
	$(MAKE) all -C $(LIBFT)
	$(GCC) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB) $(FSAN)

gimme	:
	$(MAKE) all -C $(LIBFT)
	$(GCC) $(INC) -o $(GIMME_NUM) $(LIB) $(JFF_SRCS)

re		: fclean all

.PHONY : all clean fclean norm re fsan