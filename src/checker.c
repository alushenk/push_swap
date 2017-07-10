/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 17:57:19 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/04 17:57:23 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform(t_stack *a, t_stack *b, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		sa(a);
	else if (ft_strcmp(command, "sb") == 0)
		sb(b);
	else if (ft_strcmp(command, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(command, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(command, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(command, "ra") == 0)
		ra(a);
	else if (ft_strcmp(command, "rb") == 0)
		rb(b);
	else if (ft_strcmp(command, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(command, "rra") == 0)
		rra(a);
	else if (ft_strcmp(command, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(a, b);
	else
		error_wrong_arguments();
}

void	check_sorted(t_stack *stack, t_stack *sorted_stack)
{
	int i;

	i = 0;
	while (i < stack->length)
	{
		if (stack->x->value != sorted_stack->x->value)
			error_sorting();
		rr(stack, sorted_stack);
		i++;
	}
}

void	parse_perform(char *str, t_stack *stack, t_stack *buffer)
{
	char	**strings;
	int 	i;

	strings = ft_strsplit(str, ' ');
	i = 0;
	while (strings[i] != NULL)
	{
		perform(stack, buffer, strings[i]);
		free(strings[i]);
		i++;
	}
	free(strings);
}

int		main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*sorted_stack;
	t_stack	*buffer;
	char	*str;

	if (argc < 2)
		error_no_arguments();
	g_instructions = create_list();
	buffer = create_stack();
	stack = parse_parameters(argc, argv);
	sorted_stack = insertion_sort(stack);
	while (get_next_line(0, &str) == 1)
		parse_perform(str, stack, buffer);
	check_sorted(stack, sorted_stack);
	ft_putstr("OK!\n");
}
