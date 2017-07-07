/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 16:38:25 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/07 16:38:26 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *stack, t_elem *elem)
{
	if (stack->x == NULL)
	{
		stack->x = elem;
		stack->length = 1;
		stack->x->up = elem;
		stack->x->down = elem;
		return ;
	}
	elem->down = stack->x;
	elem->up = stack->x->up;
	stack->x->up->down = elem;
	stack->x->up = elem;
	stack->x = elem;
	stack->length += 1;
}

void	push_back(t_stack *stack, t_elem *elem)
{
	push(stack, elem);
	rotate_up(stack);
}
