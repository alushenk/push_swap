/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:23:32 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 17:23:34 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**function terminates the program in case of wrong parameters
*/

int		err_atoi(const char *str)
{
	ssize_t	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || (result * sign < INT_MIN))
		{
			error_wrong_arguments();
		}
		str++;
	}
	if (*str != '\0' && ft_isdigit(*str) == 0)
	{
		error_wrong_arguments();
	}
	return (int)result * sign;
}

/*
** Function terminates the program in the case of repeated values
*/

void	find_duplicates(t_stack *stack, int num)
{
	int i;

	i = 0;
	while (i < stack->length)
	{
		if (stack->x->value == num)
			error_duplicates();
		rotate_up(stack);
		i++;
	}
}

t_stack	*parse_parameters(int len, char **argv)
{
	int		i;
	int		num;
	t_stack	*result;
	t_elem	*elem;

	result = create_stack();
	i = 1;
	while (i < len)
	{
		num = err_atoi(argv[i]);
		find_duplicates(result, num);
		elem = create_element(num);
		push_back(result, elem);
		i++;
	}
	return (result);
}
