//
// Created by Anton Lushenko on 6/24/17.
//

#include "push_swap.h"

int find_min(t_stack *stack)
{
	int result;
	int i;

	i = 0;
	result = stack->x->value;
	while(i < stack->length)
	{
		if (stack->x->value < result)
			result = stack->x->value;
		rotate_up(stack);
		i++;
	}
	return result;
}

int 	*create_array(t_stack *stack)
{
	int *result;
	int i;

	result = (int*)malloc(sizeof(int) * stack->length);
	i = 0;
	while (i < stack->length)
	{
		result[i] = stack->x->value;
		rotate_up(stack);
		i++;
	}
	return result;
}

t_stack		*insertion_sort(t_stack *stack_to_sort)
{
	int min;
	int i;
	t_stack *sorted_stack;
	t_stack *stack;

	stack = copy_stack(stack_to_sort);
	sorted_stack = create_stack();
	replace(stack, sorted_stack);
	while(stack->length > 0)
	{
		i = 0;
		while (stack->x->value > sorted_stack->x->value && i < sorted_stack->length)
		{
			rotate_up(sorted_stack);
			i++;
		}
		// kind of stupid insertion
		replace(stack, sorted_stack);
		while (i < sorted_stack->length)
		{
			rotate_up(sorted_stack);
			i++;
		}
	}

	min = find_min(sorted_stack);
	while (sorted_stack->x->value != min)
		rotate_up(sorted_stack);

	return sorted_stack;
}