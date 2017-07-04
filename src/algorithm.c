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
//void 		sort_b(t_stack *stack, int length)
//{
//	if (length == 2)
//		sort_two_descending(stack);
//	else if (length == 3)
//		sort_three_descending(stack);
//}

int		get_smaller_count(t_stack *a, int median, int length)
{
	int i;
	int result;
	t_elem *elem;

	elem = a->x;
	result = 0;
	i = 0;
	while (i < length)
	{
		if (elem->value < median)
			result += 1;
		elem = elem->down;
		i ++;
	}
	return result;
}

int		get_bigger_count(t_stack *a, int median, int length)
{
	int i;
	int result;
	t_elem *elem;

	elem = a->x;
	result = 0;
	i = 0;
	while (i < length)
	{
		if (elem->value > median)
			result += 1;
		elem = elem->down;
		i ++;
	}
	return result;
}

void		split_smaller(t_stack *a, t_stack *b, int median, int length)
{
	int i;
	int group_length;
	int displacement;
	int smaller_count;
	int initial_length;

	initial_length = length;
	smaller_count = get_smaller_count(a, median, length);
	displacement = 0;
	group_length = 0;
	i = 0;
	while(i < length && group_length < smaller_count)
	{
		if (a->x->value < median)
		{
			pb(a, b);
			length -= 1;
			group_length += 1;
		}
		else
		{
			ra(a);
			displacement += 1;
			i++;
		}
	}
	i = 0;
	while (i < displacement)
	{
		rra(a);
		i++;
	}
	b->x->group_length = group_length;
	a->x->group_length = initial_length - group_length;
}

void		split_bigger(t_stack *a, t_stack *b, int median, int length)
{
	int i;
	int group_length;
	int displacement;
	int bigger_count;
	int initial_length;

	initial_length = length;
	bigger_count = get_bigger_count(b, median, length);
	displacement = 0;
	group_length = 0;
	i = 0;
	while(i < length && group_length < bigger_count)
	{
		if (b->x->value > median)
		{
			pa(a, b);
			length -= 1;
			group_length += 1;
		}
		else
		{
			rb(b);
			displacement += 1;
			i++;
		}
	}
	i = 0;
	while (i < displacement)
	{
		rrb(b);
		i++;
	}
	b->x->group_length = initial_length - group_length;
	a->x->group_length = group_length;
}

void		replace_group(t_stack *a, t_stack *b, int group_length)
{
	int i;

	i = 0;
	while (i < group_length)
	{
		pa(a, b);
		i++;
	}
	a->x->group_length = group_length;
}

void		loop(t_stack *a, t_stack *b, t_array *sorted_array)
{
	int median;

	while (1)
	{
		sort_a(a, a->x->group_length);
		//display_both(a, b);
		//ft_putchar('\n');

		if (b->x == NULL)
			break;
		if (b->x->group_length <= 3)
		{
			replace_group(a, b, b->x->group_length);
			continue;
		}

		median = sorted_array->array[sorted_array->length - a->length - b->x->group_length / 2];
		split_bigger(a, b, median, b->x->group_length);

		//display_both(a, b);
		//ft_putchar('\n');

		if (a->x->group_length <= 3 && b->length > 0)
			continue;
		while (a->x->group_length > 3)
		{
			median = sorted_array->array[sorted_array->length - a->length + a->x->group_length / 2];
			split_smaller(a, b, median, a->x->group_length);
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

void		split_smaller_first(t_stack *a, t_stack *b, int median)
{
	int i;
	int group_length;
	int displacement;
	int smaller_count;
	int initial_length;

	initial_length = a->length;
	smaller_count = get_smaller_count(a, median, initial_length);
	displacement = 0;
	group_length = 0;
	i = 0;
	while(i < a->length && group_length < smaller_count)
	{
		if (a->x->value < median)
		{
			pb(a, b);
			group_length += 1;
		}
		else
		{
			ra(a);
			displacement += 1;
			i++;
		}
	}
	i = 0;
	if (displacement > a->length / 2)
	{
		displacement = a->length - displacement;
		while (i < displacement)
		{
			ra(a);
			i++;
		}
	}
	else
		while (i < displacement)
		{
			rra(a);
			i++;
		}
	b->x->group_length = group_length;
	a->x->group_length = initial_length - group_length;
}

t_stack		*quicksort(t_stack *a, t_stack *b, t_array *sorted_array)
{
	int median;

	//display_both(a, b);
	//ft_putchar('\n');
	while (a->length > 3 && is_sorted(a, sorted_array) == 0)
	{
		median = sorted_array->array[sorted_array->length - a->length / 2];
		split_smaller_first(a, b, median);

		//display_both(a, b);
		//ft_putchar('\n');
	}
	a->x->group_length = a->length;
	loop(a, b, sorted_array);

	return NULL;
}