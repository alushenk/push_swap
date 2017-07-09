/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:32:04 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/07 14:32:05 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack)
{
	if (stack->x == NULL || stack->length == 1)
		error_sorting();
	swap(stack);
	add_instruction(g_instructions, "sa");
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->x == NULL)
		error_sorting();
	replace(b, a);
	add_instruction(g_instructions, "pa");
}

void	ra(t_stack *stack)
{
	if (stack->x == NULL)
		error_sorting();
	rotate_up(stack);
	add_instruction(g_instructions, "ra");
}

void	rra(t_stack *stack)
{
	if (stack->x == NULL)
		error_sorting();
	rotate_down(stack);
	add_instruction(g_instructions, "rra");
}
