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
		*s++;
	if (ft_isdigit(**s) == 0)
		return (0);
	*result = i;
	return (1);
}

t_list *parse_parameters(int len, char *argv)
{
	int i;
	int num;
	char **arguments;
	t_stack *result;
	t_elem *elem;

	// create stack
	result = (t_stack*)malloc(sizeof(t_stack));
	result->start = NULL;
	result->end = NULL;

	*arguments = argv;
	i = 0;
	while (i < len)
	{
		if (skip_atoi(arguments, &num) == 0)
		{
			printf("error");
			break;
		}
		// create element
		elem = (t_elem*)malloc(sizeof(t_elem));
		elem->up = NULL;
		elem->down = NULL;
		elem->value = num;

		//check: if element in stack ERROR
		push_back(result, elem);
		i++;
	}
}