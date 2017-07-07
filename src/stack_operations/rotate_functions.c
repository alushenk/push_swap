/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 16:38:29 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/07 16:38:31 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_up(t_stack *stack)
{
	if (stack->length == 0)
		return ;
	stack->x = stack->x->down;
}

void	rotate_down(t_stack *stack)
{
	if (stack->length == 0)
		return ;
	stack->x = stack->x->up;
}
