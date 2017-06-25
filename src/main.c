#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack;

	if (argc > 1)
	{
		stack = parse_parameters(argc, argv);
		display_stack(stack);
	}
	else
		error_no_arguments();
	return 0;
}