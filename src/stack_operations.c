//
// Created by Anton Lushenko on 6/24/17.
//

#include "push_swap.h"

void	rotate_up(t_stack *stack)
{
	if (stack->length == 0)
		return ;
	stack->x = stack->x->down;
}

void	rotate_down(t_stack *stack)
{
	if (stack->length == 0)
		return ;
	stack->x = stack->x->up;
}

t_elem	*pop(t_stack *stack)
{
	t_elem *elem;

	elem = stack->x;
	if (stack->length == 0)
		return NULL;
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
	return elem;
}

t_elem	*peek(t_stack *stack)
{
	t_elem *result;

	result = create_element(stack->x->value);
	return result;
}

/*
** swaps first two elements of stack
*/
void	swap(t_stack *stack)
{
	t_elem *elem;

	elem = pop(stack);
	rotate_up(stack);
	push(stack, elem);
	rotate_down(stack);
}

t_stack	*create_stack()
{
	t_stack *result;

	result = (t_stack*)malloc(sizeof(t_stack));
	result->x = NULL;
	result->length = 0;
	return result;
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack *result;
	int 	i;

	result = create_stack();
	i = 0;
	while (i < stack->length)
	{
		push_back(result, peek(stack));
		rotate_up(stack);
		i++;
	}
	return result;
}

t_elem *create_element(int value)
{
	t_elem *result;

	result = (t_elem*)malloc(sizeof(t_elem));
	result->up = NULL;
	result->down = NULL;
	result->value = value;
	result->group = 0;

	return result;
}

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

/*
** replace first element from stack a to stack b
*/
void	replace(t_stack *a, t_stack *b)
{
	t_elem *elem;

	elem = pop(a);
	push(b, elem);
}