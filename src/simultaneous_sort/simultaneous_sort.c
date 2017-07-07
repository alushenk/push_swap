/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simultaneous_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:08:32 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/07 15:45:10 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		insert_list_a(t_inst_lst *instructions)
{
	t_inst	*instruction;
	int		i;

	instruction = instructions->x;
	i = 0;
	while (i < instructions->length)
	{
		add_instruction(g_instructions, instruction->name);
		instruction = instruction->next;
		i++;
	}
}

void		insert_list_b(t_inst_lst *instructions)
{
	t_inst	*instruction;
	int		i;

	instruction = instructions->x;
	i = 0;
	while (i < instructions->length)
	{
		rename_command_b(instruction->name);
		add_instruction(g_instructions, instruction->name);
		instruction = instruction->next;
		i++;
	}
}

t_inst_lst	*get_instructions(int length)
{
	t_inst_lst	*result;
	t_inst		*instruction;
	t_inst		*temp;
	int			i;

	result = create_list();
	g_instructions->length -= length;
	instruction = g_instructions->x;
	i = 0;
	while (i < length)
	{
		instruction = instruction->prev;
		i++;
	}
	instruction->prev->next = g_instructions->x;
	g_instructions->x->prev = instruction->prev;
	i = 0;
	while (i < length)
	{
		temp = instruction;
		instruction = instruction->next;
		insert_instruction(result, temp);
		i++;
	}
	return (result);
}

void		simultaneous_sort(t_stack *a, t_stack *b)
{
	int			count;
	int			b_group_length;
	t_inst_lst	*a_list;
	t_inst_lst	*b_list;

	if (a->x->group_length == 0 || b->x->group_length == 0)
		return ;
	b_group_length = b->x->group_length;
	count = g_instructions->length;
	sort_a(a, a->x->group_length);
	a_list = get_instructions(g_instructions->length - count);
	sort_b(b, b->x->group_length);
	b_list = get_instructions(g_instructions->length - count);
	if (b_list->x == NULL)
		insert_list_a(a_list);
	else if (a_list->x == NULL)
		insert_list_b(b_list);
	else if (a_list->length > b_list->length)
		merge_instructions_a(a_list, b_list);
	else
		merge_instructions_b(b_list, a_list);
	replace_group(a, b, b_group_length);
	free_list(a_list);
	free_list(b_list);
}
