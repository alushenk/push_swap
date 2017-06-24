#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack;

	if (argc > 1)
	{
		stack = parse_parameters(argc - 1, argv[1]);
		if (stack == NULL)
			printf("error");
	}

	printf("Hello, World!\n");
	return 0;
}