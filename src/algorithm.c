//
// Created by Anton Lushenko on 6/26/17.
//

#include "push_swap.h"

void		sort_two(t_stack *stack)
{
	int one;
	int two;

	one = stack->x->value;
	two = stack->x->down->value;

	if (one > two)
		swap(stack);
}

void		sort_three(t_stack *stack)
{

}

void		sort_a(t_stack *stack, int group)
{
	int len;
	t_elem *temp;

	// finding length of current group
	len = 0;
	temp = stack->x;
	while (temp->group == group)
	{
		len += 1;
		temp = temp->down;
	}

	if (len == 1)
		return ;
	if (len == 2)
	{
		sort_two(stack);
		return ;
	}


}

t_stack		*quicksort(t_stack *stack, int *sorted_array)
{
	int median;
	int i;
	int group;
	int half;
	int sorted_stack_length;
	t_stack *buffer;

	buffer = create_stack();

	sorted_stack_length = stack->length;
	group = 1;
	// splitting stack into groups
	while (stack->length > 3)
	{
		half = sorted_stack_length - stack->length / 2;
		median = sorted_array[half];
		i = 0;
		while (i < stack->length)
		{
			if (stack->x->value < median)
			{
				stack->x->group = group;
				replace(stack, buffer);
			}
			else
			{
				rotate_up(stack);
				i++;
			}
		}
		display_both(stack, buffer);
		ft_putchar('\n');
		group += 1;
	}
	// sorting by groups


	return NULL;
}