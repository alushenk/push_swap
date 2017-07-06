/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simultaneous_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:08:32 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 18:08:33 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rename_command(char *name)
{
	if (ft_strcmp(name, "sa") == 0)
		name[1] = 's';
	else if (ft_strcmp(name, "ra") == 0)
		name[1] = 'r';
	else if (ft_strcmp(name, "rra") == 0)
		name[2] = 'r';
}

void		rename_command_b(char *name)
{
	if (ft_strcmp(name, "sa") == 0)
		name[1] = 'b';
	else if (ft_strcmp(name, "ra") == 0)
		name[1] = 'b';
	else if (ft_strcmp(name, "rra") == 0)
		name[2] = 'b';
}

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
