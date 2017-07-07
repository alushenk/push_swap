/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:02:14 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 17:02:16 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*pop(t_stack *stack)
{
	t_elem *elem;

	elem = stack->x;
	if (stack->length == 0)
		return (NULL);
	if (stack->length == 1)
		stack->x = NULL;
	else
	{
		stack->x = stack->x->down;
		stack->x->up = elem->up;
		stack->x->up->down = stack->x;
	}
	elem->up = NULL;
	elem->down = NULL;
	stack->length -= 1;
	return (elem);
}

t_elem	*peek(t_stack *stack)
{
	t_elem *result;

	result = create_element(stack->x->value);
	return (result);
}

void	swap(t_stack *stack)
{
	t_elem *elem;

	elem = pop(stack);
	rotate_up(stack);
	push(stack, elem);
	rotate_down(stack);
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*result;
	size_t	i;

	result = create_stack();
	i = 0;
	while (i < stack->length)
	{
		push_back(result, peek(stack));
		rotate_up(stack);
		i++;
	}
	return (result);
}

void	replace(t_stack *a, t_stack *b)
{
	t_elem	*elem;

	elem = pop(a);
	push(b, elem);
}
