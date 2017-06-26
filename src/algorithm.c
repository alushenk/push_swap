//
// Created by Anton Lushenko on 6/26/17.
//

#include "push_swap.h"

t_stack		*quicksort(t_stack *stack, int *sorted_array)
{
	int median;
	int i;
	int half;
	t_stack *buffer;

	half = stack->length / 2;
	median = sorted_array[half];

	buffer = create_stack();

	i = 0;
	while (i < stack->length)
	{
		if (stack->x->value < median)
			replace(stack, buffer);
		else
		{
			rotate_up(stack);
			i++;
		}
	}
	display_both(stack, buffer);


	return NULL;
}