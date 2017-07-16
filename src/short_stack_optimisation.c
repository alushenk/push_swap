/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack_optimisation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:23:23 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/16 17:23:26 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_short_ascending(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->x->value;
	b = stack->x->down->value;
	c = stack->x->down->down->value;
	if (a > b && b > c)
		s_case_0(stack);
	else if (a > c && c > b)
		s_case_1(stack);
	else if (b > a && a > c)
		s_case_2(stack);
	else if (c > a && a > b)
		s_case_3(stack);
	else if (b > c && c > a)
		s_case_4(stack);
}

void		sort_short_descending(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->x->value;
	b = stack->x->down->value;
	c = stack->x->down->down->value;
	if (a < b && b < c)
		s_case_0(stack);
	else if (a < c && c < b)
		s_case_1(stack);
	else if (b < a && a < c)
		s_case_2(stack);
	else if (c < a && a < b)
		s_case_3(stack);
	else if (b < c && c < a)
		s_case_4(stack);
}
