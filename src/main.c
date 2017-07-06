/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:25:54 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 17:25:55 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack;
	t_stack *buffer;
	t_stack *sorted_stack;
	t_array *sorted_array;

	g_instructions = create_list();
	if (argc > 1)
	{
		stack = parse_parameters(argc, argv);
		stack->x->group_length = stack->length;
		sorted_stack = insertion_sort(stack);
		sorted_array = create_array(sorted_stack);
		buffer = create_stack();
		quicksort(stack, buffer, sorted_array);
		display_instructions(g_instructions);

//		ft_putchar('\n');
//		ft_putnbr(g_instructions->length);
//		ft_putchar('\n');
	}
	else
		error_no_arguments();
	return 0;
}
