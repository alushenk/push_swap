/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:38:14 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 17:38:15 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *stack, t_array *sorted)
{
	t_elem	*elem;
	int		start_index;
	int		i;

	start_index = sorted->length - stack->length;
	elem = stack->x;
	i = 0;
	while (i < stack->length)
	{
		if (elem->value != sorted->array[start_index + i])
			return (0);
		elem = elem->down;
		i++;
	}
	return (1);
}

int		find_min(t_stack *stack)
{
	int		result;
	size_t	i;

	i = 0;
	result = stack->x->value;
	while (i < stack->length)
	{
		if (stack->x->value < result)
			result = stack->x->value;
		rotate_up(stack);
		i++;
	}
	return (result);
}

t_array	*create_array(t_stack *stack)
{
	t_array	*result;
	int		*array;
	size_t	i;

	result = (t_array*)malloc(sizeof(t_array));
	array = (int*)malloc(sizeof(int) * stack->length);
	i = 0;
	while (i < stack->length)
	{
		array[i] = stack->x->value;
		rotate_up(stack);
		i++;
	}
	result->array = array;
	result->length = stack->length;
	return (result);
}

t_stack	*insertion_sort(t_stack *stack_to_sort)
{
	size_t	i;
	t_stack	*sorted;
	t_stack	*stack;

	stack = copy_stack(stack_to_sort);
	sorted = create_stack();
	replace(stack, sorted);
	while (stack->length > 0)
	{
		i = 0;
		while (stack->x->value > sorted->x->value && i < sorted->length)
		{
			rotate_up(sorted);
			i++;
		}
		replace(stack, sorted);
		while (i < sorted->length)
		{
			rotate_up(sorted);
			i++;
		}
	}
	free(stack);
	return (sorted);
}
