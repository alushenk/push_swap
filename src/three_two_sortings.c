//
// Created by Anton Lushenko on 6/28/17.
//

#include "push_swap.h"

// sorts top two elements of stack
void		sort_two_ascending(t_stack *stack)
{
	int one;
	int two;

	one = stack->x->value;
	two = stack->x->down->value;

	if (one > two)
		sa(stack);
}

// sorts top two elements of stack
void		sort_two_descending(t_stack *stack)
{
	int one;
	int two;

	one = stack->x->value;
	two = stack->x->down->value;

	if (one < two)
		sb(stack);
}

// sorts top three elements of stack
void		sort_three_ascending(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->x->value;
	b = stack->x->down->value;
	c = stack->x->down->down->value;

	if (a > b && b > c)
		case_0(stack);
	else if (a > c && c > b)
		case_1(stack);
	else if (b > a && a > c)
		case_2(stack);
	else if (c > a && a > b)
		case_3(stack);
	else if (b > c && c > a)
		case_4(stack);
}

void		sort_three_descending(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->x->value;
	b = stack->x->down->value;
	c = stack->x->down->down->value;

	if (a < b < c)
		case_0(stack);
	else if (a < c < b)
		case_1(stack);
	else if (b < a < c)
		case_2(stack);
	else if (c < a < b)
		case_3(stack);
	else if (b < c < a)
		case_4(stack);
}