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

void	add_instruction(t_instructions *list, char *name)
{
	t_instruction *instruction;

	instruction = create_instruction(name);
	if (list->x == NULL)
	{
		list->x = instruction;
		list->length = 1;
		list->x->prev = instruction;
		list->x->next = instruction;
		return ;
	}
	instruction->next = list->x;
	instruction->prev = list->x->prev;
	list->x->prev->next = instruction;
	list->x->prev = instruction;
	list->length += 1;
}

t_instructions	*create_list()
{
	t_instructions *result;

	result = (t_instructions*)malloc(sizeof(t_instructions));
	result->x = NULL;
	result->length = 0;

	return result;
}