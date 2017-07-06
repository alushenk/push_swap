/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:36:22 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 17:36:23 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instruction	*create_instruction(char *name)
{
	t_instruction *result;

	result = (t_instruction*)malloc(sizeof(t_instruction));
	result->name = ft_strdup(name);
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

void			add_instruction(t_instructions *list, char *name)
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

t_instructions	*create_list(void)
{
	t_instructions *result;

	result = (t_instructions*)malloc(sizeof(t_instructions));
	result->x = NULL;
	result->length = 0;
	return (result);
}
