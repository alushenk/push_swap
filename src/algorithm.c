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

void		split_smaller(t_stack *a, t_stack *b, int median, int length)
{
	int i;
	int group_length;
	int displacement;

	displacement = 0;
	group_length = 0;
	i = 0;
	// scrolls entire list, can be optimised
	while(i < length)
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
	a->x->group_length = displacement;
}

void		split_bigger(t_stack *a, t_stack *b, int median, int length)
{
	int i;
	int group_length;
	int displacement;

	displacement = 0;
	group_length = 0;
	i = 0;
	// scrolls entire list, can be optimised
	while(i < length)
	{
		if (b->x->value >= median)
		{
			pa(a, b);
			length -= 1;
			group_length += 1;
		}
		else
		{
			ra(b);
			displacement += 1;
			i++;
		}
	}
	i = 0;
	while (i < displacement)
	{
		rra(b);
		i++;
	}
	b->x->group_length = displacement;
	a->x->group_length = group_length;
}

void		replace_group(t_stack *a, t_stack *b, int group_length)
{
	int i;

	i = 0;
	while (i < group_length)
	{
		pb(a, b);
		i++;
	}
	b->x->group_length = group_length;
}

void		loop(t_stack *a, t_stack *b, t_array *sorted_array)
{
	int median;

	while (1)
	{
		sort_a(a, a->x->group_length);
		display_both(a, b);
		ft_putchar('\n');

		if (b->x == NULL)
			break;
		if (b->x->group_length <= 3)
		{
			replace_group(b, a, b->x->group_length);
			continue;
		}

		median = sorted_array->array[sorted_array->length - a->length - b->x->group_length / 2];
		split_bigger(a, b, median, b->x->group_length);

		display_both(a, b);
		ft_putchar('\n');

		if (a->x->group_length <= 3 && b->length > 0)
			continue;
		else
		{
			while (a->x->group_length > 3)
			{
				median = sorted_array->array[sorted_array->length - a->length + a->x->group_length / 2];
				split_smaller(a, b, median, a->x->group_length);
			}
			continue;
		}
	}
}

t_stack		*quicksort(t_stack *a, t_stack *b, t_array *sorted_array)
{
	int median;

	while (a->length > 3)
	{
		median = sorted_array->array[sorted_array->length - a->length / 2];
		split_smaller(a, b, median, a->length);
		display_both(a, b);
		ft_putchar('\n');
	}
	a->x->group_length = a->length;
	sort_a(a, a->x->group_length);
	loop(a, b, sorted_array);

	return NULL;
}