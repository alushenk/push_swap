/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_two_sortings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:10:33 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 17:10:35 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_two_ascending(t_stack *stack)
{
	int one;
	int two;

	one = stack->x->value;
	two = stack->x->down->value;
	if (one > two)
		sa(stack);
}

void		sort_two_descending(t_stack *stack)
{
	int one;
	int two;

	one = stack->x->value;
	two = stack->x->down->value;
	if (one < two)
		sb(stack);
}

void		sort_three_ascending(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->x->value;
	b = stack->x->down->value;
	c = stack->x->down->down->value;
	if (a > b && b > c)
		case_0(stack);
	else if (a > c && c > b)
		case_1(stack);
	else if (b > a && a > c)
		case_2(stack);
	else if (c > a && a > b)
		case_3(stack);
	else if (b > c && c > a)
		case_4(stack);
}

void		sort_three_descending(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->x->value;
	b = stack->x->down->value;
	c = stack->x->down->down->value;
	if (a < b && b < c)
		case_0(stack);
	else if (a < c && c < b)
		case_1(stack);
	else if (b < a && a < c)
		case_2(stack);
	else if (c < a && a < b)
		case_3(stack);
	else if (b < c && c < a)
		case_4(stack);
}
