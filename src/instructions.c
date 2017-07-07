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

t_inst		*create_instruction(char *name)
{
	t_inst *result;

	result = (t_inst*)malloc(sizeof(t_inst));
	result->name = ft_strdup(name);
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

void		add_instruction(t_inst_lst *list, char *name)
{
	t_inst *instruction;

	instruction = create_instruction(name);
	insert_instruction(list, instruction);
}

void		insert_instruction(t_inst_lst *list, t_inst *instruction)
{
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

t_inst_lst	*create_list(void)
{
	t_inst_lst *result;

	result = (t_inst_lst*)malloc(sizeof(t_inst_lst));
	result->x = NULL;
	result->length = 0;
	return (result);
}

void		free_list(t_inst_lst *list)
{
	t_inst	*elem;
	t_inst	*temp;
	int		i;

	elem = list->x;
	i = 0;
	while (i < list->length)
	{
		temp = elem;
		elem = elem->next;
		free(temp->name);
		free(temp);
		i++;
	}
	free(list);
}
