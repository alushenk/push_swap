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

//int			get_group_length(t_stack *stack)
//{
//	int len;
//	int group;
//	t_elem *temp;
//
//	group = stack->x->group;
//	len = 0;
//	temp = stack->x;
//	while (temp->group == group && len < stack->length)
//	{
//		len += 1;
//		temp = temp->down;
//	}
//	return len;
//}

int 		find_median(t_array *sorted_array, int start, int len)
{
	int median;

	median = sorted_array->array[start - len / 2];

	return median;
}

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
			replace(a, b);
			length -= 1;
			group_length += 1;
		}
		else
		{
			rotate_up(a);
			displacement += 1;
			i++;
		}
	}
	i = 0;
	while (i < displacement)
	{
		rotate_down(a);
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
			replace(b, a);
			length -= 1;
			group_length += 1;
		}
		else
		{
			rotate_up(b);
			displacement += 1;
			i++;
		}
	}
	i = 0;
	while (i < displacement)
	{
		rotate_down(b);
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
		replace(a, b);
		i++;
	}
	b->x->group_length = group_length;
}

void		loop(t_stack *a, t_stack *b, t_array *sorted_array)
{
	int median;

	display_both(a, b);
	ft_putchar('\n');
	sort_a(a, a->x->group_length);
	// тут крашится когда b уже пустой
	if (b->x->group_length <= 3)
	{
		replace_group(b, a, b->x->group_length);
		loop(a, b, sorted_array);
	}

	median = sorted_array->array[sorted_array->length - a->length - b->x->group_length / 2];
	split_bigger(a, b, median, b->x->group_length);
	display_both(a, b);
	ft_putchar('\n');

	while (a->x->group_length > 3)
	{
		median = sorted_array->array[sorted_array->length - a->length + a->x->group_length / 2];
		split_bigger(b, a, median, a->x->group_length);
	}


	if (a->x->group_length <= 3)
		loop(a, b, sorted_array);
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
	loop(a, b, sorted_array);



	return NULL;
}