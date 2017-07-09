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

#include "../push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	if (a->x == NULL || b->x == NULL || a->length == 1 || b->length == 1)
		error_sorting();
	swap(a);
	swap(b);
	add_instruction(g_instructions, "ss");
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->x == NULL || b->x == NULL)
		error_sorting();
	rotate_up(a);
	rotate_up(b);
	add_instruction(g_instructions, "rr");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->x == NULL || b->x == NULL)
		error_sorting();
	rotate_down(a);
	rotate_down(b);
	add_instruction(g_instructions, "rrr");
}
