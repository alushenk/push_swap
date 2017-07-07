/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 16:38:20 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/07 16:38:22 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*create_element(int value)
{
	t_elem *result;

	result = (t_elem*)malloc(sizeof(t_elem));
	result->up = NULL;
	result->down = NULL;
	result->value = value;
	result->group_length = 0;
	return (result);
}

t_stack	*create_stack(void)
{
	t_stack *result;

	result = (t_stack*)malloc(sizeof(t_stack));
	result->x = NULL;
	result->length = 0;
	return (result);
}
