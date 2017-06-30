//
// Created by Anton Lushenko on 6/28/17.
//

#include "push_swap.h"

t_instruction *create_instruction(char *name)
{
	t_instruction *result;

	result = (t_instruction*)malloc(sizeof(t_instruction));
	result->name = ft_strdup(name);
	return result;
}

void	add_instruction(char *name)
{
	t_instruction *instruction;

	instruction = create_instruction(name);
	instruction->next = g_instructions->x;
	g_instructions->x = instruction;
	g_instructions->length += 1;
}

void sa(t_stack *stack)
{
	swap(stack);
	add_instruction("sa");
}

void sb(t_stack *stack)
{
	swap(stack);
	add_instruction("sb");
}

void ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	add_instruction("ss");
}

void pa(t_stack *a, t_stack *b)
{
	replace(b, a);
	add_instruction("pa");
}

void pb(t_stack *a, t_stack *b)
{
	replace(a, b);
	add_instruction("pb");
}

void ra(t_stack *stack)
{
	rotate_up(stack);
	add_instruction("ra");
}

void rb(t_stack *stack)
{
	rotate_up(stack);
	add_instruction("rb");
}

void rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	add_instruction("rr");
}

void rra(t_stack *stack)
{
	rotate_down(stack);
	add_instruction("rra");
}

void rrb(t_stack *stack)
{
	rotate_down(stack);
	add_instruction("rrb");
}

void rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	add_instruction("rrr");
}