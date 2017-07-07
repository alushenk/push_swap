/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:35:19 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/07 14:35:20 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack *stack)
{
	swap(stack);
	add_instruction(g_instructions, "sb");
}

void	pb(t_stack *a, t_stack *b)
{
	replace(a, b);
	add_instruction(g_instructions, "pb");
}

void	rb(t_stack *stack)
{
	rotate_up(stack);
	add_instruction(g_instructions, "rb");
}

void	rrb(t_stack *stack)
{
	rotate_down(stack);
	add_instruction(g_instructions, "rrb");
}
