//
// Created by Anton Lushenko on 6/24/17.
//

#include "push_swap.h"

void	push_back(t_stack *stack, t_elem *elem)
{
	push(stack, elem);
	rotate_up(stack);
}