/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 12:07:15 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/05 12:07:17 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_smaller_count(t_stack *a, int median, int length)
{
	int		i;
	int		result;
	t_elem	*elem;

	elem = a->x;
	result = 0;
	i = 0;
	while (i < length)
	{
		if (elem->value < median)
			result += 1;
		elem = elem->down;
		i++;
	}
	return (result);
}

int		get_bigger_count(t_stack *a, int median, int length)
{
	int		i;
	int		result;
	t_elem	*elem;

	elem = a->x;
	result = 0;
	i = 0;
	while (i < length)
	{
		if (elem->value >= median)
			result += 1;
		elem = elem->down;
		i++;
	}
	return (result);
}

void	split(t_stack *a, t_stack *b, void func(t_stack *a, t_stack *b))
{

}

void	split_smaller_first(t_stack *a, t_stack *b, int median)
{
	int	group_length;
	int	displacement;
	int	smaller_count;
	int	initial_length;

	initial_length = a->length;
	smaller_count = get_smaller_count(a, median, initial_length);
	displacement = 0;
	group_length = 0;
	while (displacement < a->length && group_length < smaller_count)
	{
		if (a->x->value < median)
		{
			pb(a, b);
			group_length += 1;
		}
		else
		{
			ra(a);
			displacement++;
		}
	}
	if (displacement > a->length / 2)
	{
		displacement = a->length - displacement;
		while (displacement > 0)
		{
			ra(a);
			displacement--;
		}
	}
	else
		while (displacement > 0)
		{
			rra(a);
			displacement--;
		}
	b->x->group_length = group_length;
	a->x->group_length = initial_length - group_length;
}

void	split_bigger(t_stack *a, t_stack *b, int median)
{
	int	group_length;
	int	displacement;
	int	bigger_count;
	int	initial_length;

	initial_length = b->x->group_length;
	bigger_count = get_bigger_count(b, median, initial_length);
	displacement = 0;
	group_length = 0;
	while (displacement < b->length && group_length < bigger_count)
	{
		if (b->x->value >= median)
		{
			pa(a, b);
			group_length += 1;
		}
		else
		{
			rb(b);
			displacement++;
		}
	}
	while (displacement > 0)
	{
		rrb(b);
		displacement--;
	}
	b->x->group_length = initial_length - group_length;
	a->x->group_length = group_length;
}

void	split_smaller(t_stack *a, t_stack *b, int median)
{
	int	group_length;
	int	displacement;
	int	smaller_count;
	int	initial_length;

	initial_length = a->x->group_length;
	smaller_count = get_smaller_count(a, median, initial_length);
	displacement = 0;
	group_length = 0;
	while (displacement < a->length && group_length < smaller_count)
	{
		if (a->x->value < median)
		{
			pb(a, b);
			group_length += 1;
		}
		else
		{
			ra(a);
			displacement++;
		}
	}
	while (displacement > 0)
	{
		rra(a);
		displacement--;
	}
	b->x->group_length = group_length;
	a->x->group_length = initial_length - group_length;
}
