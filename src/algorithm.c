//
// Created by Anton Lushenko on 6/26/17.
//

#include "push_swap.h"



// sorting in ascending order
void		sort_a(t_stack *stack, int length)
{
	if (length == 2)
		sort_two_ascending(stack);
	else if (length == 3)
		sort_three_ascending(stack);
}

// sorting in descending order
void 		sort_b(t_stack *stack, int length)
{
	if (length == 2)
		sort_two_descending(stack);
	else if (length == 3)
		sort_three_descending(stack);
}

int			get_group_length(t_stack *stack)
{
	int len;
	int group;
	t_elem *temp;

	group = stack->x->group;
	len = 0;
	temp = stack->x;
	while (temp->group == group && len < stack->length)
	{
		len += 1;
		temp = temp->down;
	}
	return len;
}

int 		find_median(t_stack *stack, t_array *sorted_array, int length, int displacement)
{
	int median;
	int half;

	half = sorted_array->length - displacement - length / 2;
	median = sorted_array->array[half];

	return median;
}

void		split(t_stack *a, t_stack *b, t_array *sorted_array, int length_a, int length_b, int need_replace)
{
	int median;
	int group_length;
	int i;
	int displacement;

	if (length_a <= 3)
	{
		sort_a(a, length_a);
		if (length_b <= 3)
			sort_a(b, length_b);
		else
			split(b, a, sorted_array, group_length, length_a, 1);
		return;
	}

	if (need_replace)
		displacement = b->length;
	else
		displacement = 0;
	median = find_median(a, sorted_array, length_a, displacement);
	group_length = 0;
	i = 0;
	// moving half the "a" to the "b"
	while (i < length_a)
	{
		if (a->x->value < median)
		{
			replace(a, b);
			group_length += 1;
			length_a -= 1;
		}
		else
		{
			rotate_up(a);
			i++;
		}
	}
	while (i > 0)
	{
		rotate_down(a);
		i--;
	}

	display_both(a, b);
	ft_putchar('\n');

	split(a, b, sorted_array, length_a, group_length, need_replace);
	display_both(a, b);
	ft_putchar('\n');

	if (need_replace == 0)
		need_replace = 1;
	else
		need_replace = 0;
	split(b, a, sorted_array, group_length, length_a, need_replace);

	while (group_length)
	{
		replace(b, a);
		group_length--;
	}
}

t_stack		*quicksort(t_stack *stack, t_stack *buffer, t_array *sorted_array)
{
	int group_length;

	// splitting stack while length > 3
	// buffer->length == 0 by default
	split(stack, buffer, sorted_array, stack->length, buffer->length, 0);

	return NULL;
}