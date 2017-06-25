//
// Created by Anton Lushenko on 6/24/17.
//

#include "push_swap.h"

/*
** function can terminate the program in case of errors
*/
int	err_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result > INT_MAX || (result > -INT_MIN && sign == -1))
			error_wrong_arguments();
		str++;
	}
	if (*str != '\0' && ft_isdigit(*str) == 0)
		error_wrong_arguments();
	return result * sign;
}

t_stack *parse_parameters(int len, char **argv)
{
	int i;
	int num;
	t_stack *result;
	t_elem *elem;

	// create stack
	result = (t_stack*)malloc(sizeof(t_stack));
	result->x = NULL;
	result->length = 0;

	i = 1;
	while (i < len)
	{
		num = err_atoi(argv[i]);
		// create element
		elem = (t_elem*)malloc(sizeof(t_elem));
		elem->up = NULL;
		elem->down = NULL;
		elem->value = num;
		elem->portion_index = 0;

		//check: if element in stack ERROR

		push_back(result, elem);
		i++;
	}
	return result;
}