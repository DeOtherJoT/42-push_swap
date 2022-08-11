GCC		= gcc -Wall -Wextra -Werror -I../includes -I../libft ../sources/operation/*.c ../sources/stacks/*.c ../libft/*.c
FSAN	= -fsanitize=address -g

cincai	:
	$(GCC) $(FSAN) test_operations.c -o test.out

fclean :
	rm -rf test.out
	rm -rf test.out.dSYM