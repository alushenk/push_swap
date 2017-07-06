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

void	split_smaller_first(t_stack *a, t_stack *b, int median)
{
	int	group_length;
	int	smaller_count;
	int	initial_length;

	initial_length = a->length;
	smaller_count = get_smaller_count(a, median, initial_length);
	group_length = 0;
	while (group_length < smaller_count)
	{
		if (a->x->value < median)
		{
			pb(a, b);
			group_length += 1;
		}
		else
			ra(a);
	}
	b->x->group_length = group_length;
	a->x->group_length = initial_length - group_length;
}

void	split_bigger(t_stack *a, t_stack *b, int median, int initial_length)
{
	int	group_length;
	int	displacement;
	int	bigger_count;
	int need_replace;

	need_replace = (initial_length == b->length) ? 0 : 1;
	bigger_count = get_bigger_count(b, median, initial_length);
	displacement = 0;
	group_length = 0;
	while (group_length < bigger_count)
	{
		if (b->x->value >= median)
		{
			pa(a, b);
			group_length += 1;
			continue;
		}
		rb(b);
		displacement++;
	}
	while (--displacement >= 0 && need_replace)
		rrb(b);
	b->x->group_length = initial_length - group_length;
	a->x->group_length = group_length;
}

void	split_smaller(t_stack *a, t_stack *b, int median, int initial_length)
{
	int	group_length;
	int	displacement;
	int	smaller_count;

	smaller_count = get_smaller_count(a, median, initial_length);
	displacement = 0;
	group_length = 0;
	while (group_length < smaller_count)
	{
		if (a->x->value < median)
		{
			pb(a, b);
			group_length += 1;
			continue;
		}
		ra(a);
		displacement++;
	}
	while (--displacement >= 0)
		rra(a);
	b->x->group_length = group_length;
	a->x->group_length = initial_length - group_length;
}
