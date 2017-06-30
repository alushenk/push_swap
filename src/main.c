#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack;
	t_stack *buffer;
	t_stack *sorted_stack;
	t_array *sorted_array;

	g_instructions = (t_instructions*)malloc(sizeof(t_instructions));
	g_instructions->length = 0;

	if (argc > 1)
	{
		stack = parse_parameters(argc, argv);

		// the first group
		stack->x->group_length = stack->length;

		display_stack(stack);

		ft_putchar('\n');

		sorted_stack = insertion_sort(stack);
		sorted_array = create_array(sorted_stack);
		display_array(sorted_array);

		ft_putchar('\n');

		buffer = create_stack();
		quicksort(stack, buffer, sorted_array);

		display_both(stack, buffer);

		ft_putchar('\n');
		ft_putnbr(g_instructions->length);
	}
	else
		error_no_arguments();
	return 0;
}