//
// Created by Anton Lushenko on 7/4/17.
//

#include "push_swap.h"

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

void		split_bigger(t_stack *a, t_stack *b, int median)
{
	int i;
	int group_length;
	int displacement;
	int bigger_count;
	int initial_length;

	initial_length = b->x->group_length;
	bigger_count = get_bigger_count(b, median, initial_length);
	displacement = 0;
	group_length = 0;
	i = 0;
	while(i < b->length && group_length < bigger_count)
	{
		if (b->x->value > median)
		{
			pa(a, b);
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

void		split_smaller(t_stack *a, t_stack *b, int median)
{
	int i;
	int group_length;
	int displacement;
	int smaller_count;
	int initial_length;

	initial_length = a->x->group_length;
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
	while (i < displacement)
	{
		rra(a);
		i++;
	}
	b->x->group_length = group_length;
	a->x->group_length = initial_length - group_length;
}