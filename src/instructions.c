//
// Created by Anton Lushenko on 7/5/17.
//

#include "push_swap.h"

t_instruction *create_instruction(char *name)
{
	t_instruction *result;

	result = (t_instruction*)malloc(sizeof(t_instruction));
	result->name = ft_strdup(name);
	result->next = NULL;
	result->prev = NULL;
	return result;
}

void	add_instruction(char *name)
{
	t_instruction *instruction;

	instruction = create_instruction(name);
	if (g_instructions->x == NULL)
	{
		g_instructions->x = instruction;
		g_instructions->length = 1;
		g_instructions->x->prev = instruction;
		g_instructions->x->next = instruction;
		return ;
	}
	instruction->next = g_instructions->x;
	instruction->prev = g_instructions->x->prev;
	g_instructions->x->prev->next = instruction;
	g_instructions->x->prev = instruction;
	g_instructions->length += 1;
}

t_instructions	*create_list()
{
	t_instructions *result;

	result = (t_instructions*)malloc(sizeof(t_instructions));
	result->x = NULL;
	result->length = 0;

	return result;
}