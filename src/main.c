#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack;

	if (argc > 1)
	{
		stack = parse_parameters(argc, argv);
		if (stack == NULL)
			ft_putstr("error");
		display_stack(stack);
	}
	else
		ft_putstr("pass the parameters, please");
	return 0;
}