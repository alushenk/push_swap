//
// Created by Anton Lushenko on 6/24/17.
//

#include "push_swap.h"

/*
** returning zero: not int, > int_max
*/
int		skip_atoi(char **s, int *result)
{
	size_t i;

	i = 0;
	while (ft_isdigit(**s))
	{
		i = i * 10 + *((*s)++) - '0';
		if (i > INT_MAX)
			return (0);
	}
	while(ft_isspace(**s))
		(*s)++;
	if (**s != '\0' && ft_isdigit(**s) == 0)
		return (0);
	*result = i;
	return (1);
}

int	err_atoi(const char *str, int *err)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' && ft_isdigit(*str) == 0)
		*err = 1;
	else
		*err = 0;
	return result * sign;
}

t_stack *parse_parameters(int len, char **argv)
{
	int i;
	int num;
	t_stack *result;
	t_elem *elem;
	int err;

	// create stack
	result = (t_stack*)malloc(sizeof(t_stack));
	result->x = NULL;
	result->length = 0;

	num = 0;
	err = 0;
	i = 1;
	// tut dopilit
	while (i < len)
	{
		num = err_atoi(argv[i], &err);
		if (err_atoi(argv[i], &num) == 0)
		{
			printf("error");
			return NULL;
		}
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