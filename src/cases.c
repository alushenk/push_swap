//
// Created by Anton Lushenko on 6/28/17.
//

#include "push_swap.h"

void 		case_0(t_stack *stack)
{
	swap(stack);
	rotate_up(stack);
	swap(stack);
	rotate_down(stack);
	swap(stack);
}

void		case_1(t_stack *stack)
{
	swap(stack);
	rotate_up(stack);
	swap(stack);
	rotate_down(stack);
}

void 		case_2(t_stack *stack)
{
	rotate_up(stack);
	swap(stack);
	rotate_down(stack);
	swap(stack);
}

void		case_3(t_stack *stack)
{
	swap(stack);
}

void		case_4(t_stack *stack)
{
	rotate_up(stack);
	swap(stack);
	rotate_down(stack);
}