/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:08:12 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 20:08:13 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	swap(stack);
	add_instruction(g_instructions, "sa");
}

void	sb(t_stack *stack)
{
	swap(stack);
	add_instruction(g_instructions, "sb");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	add_instruction(g_instructions, "ss");
}

void	pa(t_stack *a, t_stack *b)
{
	replace(b, a);
	add_instruction(g_instructions, "pa");
}

void	pb(t_stack *a, t_stack *b)
{
	replace(a, b);
	add_instruction(g_instructions, "pb");
}

void	ra(t_stack *stack)
{
	rotate_up(stack);
	add_instruction(g_instructions, "ra");
}

void	rb(t_stack *stack)
{
	rotate_up(stack);
	add_instruction(g_instructions, "rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	add_instruction(g_instructions, "rr");
}

void	rra(t_stack *stack)
{
	rotate_down(stack);
	add_instruction(g_instructions, "rra");
}

void	rrb(t_stack *stack)
{
	rotate_down(stack);
	add_instruction(g_instructions, "rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	add_instruction(g_instructions, "rrr");
}
