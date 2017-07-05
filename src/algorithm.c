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

void		replace_group(t_stack *a, t_stack *b, int group_length)
{
	int i;

	i = 0;
	while (i < group_length)
	{
		pa(a, b);
		sort_two_ascending(a);
		i++;
	}
	a->x->group_length = group_length;
}

// мало пользы. по сути без этого происходит то же самое, только по три.
// норм было бы изначально не перемещать в Б отсортированные куски.
//		if (is_sorted_group(b, sorted_array, b->x->group_length, a->length))
//		{
//			replace_group(a, b, b->x->group_length);
//			continue;
//		}
int		is_sorted_group(t_stack *stack, t_array *sorted_array, int group_length, int a_length)
{
	t_elem	*elem;
	int		start_index;

	elem = stack->x;
	start_index = sorted_array->length - a_length - 1;
	while (group_length > 0)
	{
		if (elem->value != sorted_array->array[start_index])
			return (0);
		elem = elem->down;
		start_index--;
		group_length--;
	}
	return (1);
}



void		loop(t_stack *a, t_stack *b, t_array *sorted_array)
{
	int median;

	while (b->x != NULL)
	{
		//display_instructions(g_instructions);
		//ft_putchar('\n');

		if (a->x->group_length <= 3 && b->x->group_length <= 3)
			simultaneous_sort(a, b);

		//display_instructions(g_instructions);
		//ft_putchar('\n');

		//display_both(a, b);
		//ft_putchar('\n');

		sort_a(a, a->x->group_length);
		if (b->x == NULL)
			break;
		if (b->x->group_length <= 3)
		{
			replace_group(a, b, b->x->group_length);
			continue;
		}

		median = sorted_array->array[sorted_array->length - a->length - b->x->group_length / 2];
		split_bigger(a, b, median);
		while (a->x->group_length > 3)
		{
			median = sorted_array->array[sorted_array->length - a->length + a->x->group_length / 2];
			split_smaller(a, b, median);
		}
	}
}

int 		is_sorted(t_stack *stack, t_array *sorted_array)
{
	t_elem *elem;
	int start_index;
	int i;

	start_index = sorted_array->length - stack->length;
	elem = stack->x;
	i = 0;
	while (i < stack->length)
	{
		if (elem->value != sorted_array->array[start_index + i])
			return (0);
		elem = elem->down;
		i++;
	}
	return (1);
}

void	quicksort(t_stack *a, t_stack *b, t_array *sorted_array)
{
	int median;

	while (a->length > 3 && is_sorted(a, sorted_array) == 0)
	{
		median = sorted_array->array[sorted_array->length - a->length / 2];
		split_smaller_first(a, b, median);
	}
	a->x->group_length = a->length;
	loop(a, b, sorted_array);
}