GCC		= gcc -Wall -Wextra -Werror -I../includes -I../libft ../sources/input/*.c ../sources/stacks/*.c ../libft/*.c
FSAN	= -fsanitize=address -g

cincai	:
	$(GCC) $(FSAN) test_input_init.c -o test.out
