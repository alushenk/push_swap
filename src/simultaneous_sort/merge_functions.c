/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:44:59 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/07 15:45:01 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		insert_result(t_inst_lst *list)
{
	t_inst	*instruction;
	int		i;

	instruction = list->x;
	i = 0;
	while (i < list->length)
	{
		add_instruction(g_instructions, instruction->name);
		instruction = instruction->next;
		i++;
	}
}

void		merge(t_inst_lst *a, t_inst_lst *b, int *i, int *j)
{
	*j = 0;
	while (*i < a->length && *j < b->length && !strcmp(a->x->name, b->x->name))
	{
		rename_command(a->x->name);
		a->x = a->x->next;
		b->x = b->x->next;
		(*j)++;
		(*i)++;
	}
}

void		merge_instructions_a(t_inst_lst *a, t_inst_lst *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->length && strcmp(a->x->name, b->x->name))
	{
		a->x = a->x->next;
		i++;
	}
	merge(a, b, &i, &j);
	while (i < a->length)
	{
		a->x = a->x->next;
		i++;
	}
	while (j < b->length)
	{
		rename_command_b(b->x->name);
		add_instruction(a, b->x->name);
		b->x = b->x->next;
		j++;
	}
	insert_result(a);
}

void		merge_instructions_b(t_inst_lst *a, t_inst_lst *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->length && strcmp(a->x->name, b->x->name))
	{
		rename_command_b(a->x->name);
		a->x = a->x->next;
		i++;
	}
	merge(a, b, &i, &j);
	while (i < a->length)
	{
		rename_command_b(a->x->name);
		a->x = a->x->next;
		i++;
	}
	while (j < b->length)
	{
		add_instruction(a, b->x->name);
		b->x = b->x->next;
		j++;
	}
	insert_result(a);
}
