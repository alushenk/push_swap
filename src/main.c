#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack;
	t_stack *sorted_stack;
	int 	*sorted_array;

	if (argc > 1)
	{
		stack = parse_parameters(argc, argv);
		display_stack(stack);

		ft_putchar('\n');

		sorted_stack = insertion_sort(stack);
		sorted_array = create_array(sorted_stack);
		display_array(sorted_array, sorted_stack->length);

		ft_putchar('\n');

		quicksort(stack, sorted_array);
	}
	else
		error_no_arguments();
	return 0;
}