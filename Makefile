#EXEC NAME#

NAME	= push_swap

#FLAGS#

GCC		= gcc -Wall -Wextra -Werror
FSAN	= -fsanitize=address -g
RM		= rm -rf

#PATH LIB#

LIBFT	= libft
INC		= -Iinclude -I$(LIBFT)
LIB		= -L$(LIBFT) libft/libft.a
SRC_DIR	= sources/
ALG_DIR	= sources/algo/
DRV_DIR	= sources/driver/
INP_DIR	= sources/input/
OPR_DIR	= sources/operation/
STK_DIR	= sources/stacks/
MAIN	= $(DRV_DIR)main.c

#SOURCE FILES#

SRCS	= $(addprefix $(ALG_DIR), decide_sort.c sort_simple.c sort_utils.c) \
		  $(addprefix $(INP_DIR), check_input.c input_utils.c process_input.c temp_sort.c) \
		  $(addprefix $(OPR_DIR), move_elem.c op_ins_1.c op_ins_2.c op_ins_3.c op_utils.c) \
		  $(addprefix $(STK_DIR), stacks_init.c)
OBJS	= $(SRCS:.c=.o)

#RECIPES#

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) re -C $(LIBFT)
	$(GCC) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB)

%.o : %.c
	$(GCC) $(INC) -c $< -o $@

clean :
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(RM) push_swap.dSYM
	$(MAKE) fclean -C $(LIBFT);

norm :
	norminette $(SRC_DIR)
	norminette includes/push_swap.h

re : fclean all

.PHONY : all clean fclean norm re