//
// Created by Anton Lushenko on 6/24/17.
//

#include "push_swap.h"

void 	push(t_stack *stack, t_elem *elem)
{
	t_elem *temp;

	if (stack->x == NULL)
	{
		stack->x = elem;
		stack->length = 1;
		// self interlock
		stack->x->up = elem;
		stack->x->down = elem;
		return ;
	}
	elem->down = stack->x;
	stack->x->up->down = elem;
	stack->x->up = elem;
	stack->x = elem;
	stack->length += 1;
}

void	rotate_up(t_stack *stack)
{
	if (stack->length == 1)
		return ;
	stack->x = stack->x->down;
}

void	push_back(t_stack *stack, t_elem *elem)
{
	push(stack, elem);
	rotate_up(stack);
}
