GCC		= gcc -Wall -Wextra -Werror -I../includes -I../libft ../sources/algo/sort_complex/decide*.c ../sources/stacks/*.c ../libft/*.c
FSAN	= -fsanitize=address -g

cincai	:
	$(GCC) $(FSAN) test_decide_partition.c -o test.out
