/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:02:55 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 17:03:09 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack *stack, int length)
{
	if (length == 2)
		sort_two_ascending(stack);
	else if (length == 3)
		sort_three_ascending(stack);
}

void	sort_b(t_stack *stack, int length)
{
	if (length == 2)
		sort_two_descending(stack);
	else if (length == 3)
		sort_three_descending(stack);
}

void	replace_group(t_stack *a, t_stack *b, int group_length)
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

void	loop(t_stack *a, t_stack *b, t_array *sorted)
{
	int median;
	int index;

	while (1)
	{
		if (b->x != NULL && a->x->group_length <= 3 && b->x->group_length <= 3)
			simultaneous_sort(a, b);
		sort_a(a, a->x->group_length);
		if (b->x == NULL)
			break ;
		if (b->x->group_length <= 3)
		{
			replace_group(a, b, b->x->group_length);
			continue;
		}
		index = sorted->length - a->length - b->x->group_length / 2;
		median = sorted->array[index];
		split_b(a, b, median, b->x->group_length);
		while (a->x->group_length > 3)
		{
			index = sorted->length - a->length + a->x->group_length / 2;
			median = sorted->array[index];
			split_a(a, b, median, a->x->group_length);
		}
	}
}

void	quicksort(t_stack *a, t_stack *b, t_array *sorted)
{
	int median;

	while (a->length > 3 && is_sorted(a, sorted) == 0)
	{
		median = sorted->array[sorted->length - a->length / 2];
		split_a_first(a, b, median);
	}
	a->x->group_length = a->length;
	loop(a, b, sorted);
}
