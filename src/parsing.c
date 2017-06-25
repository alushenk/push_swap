//
// Created by Anton Lushenko on 6/24/17.
//

#include "push_swap.h"

/*
** function terminates the program in case of wrong parameters
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

t_stack *parse_parameters(int len, char **argv)
{
	int i;
	int num;
	t_stack *result;
	t_elem *elem;

	/*
	** creating stack
	*/
	result = (t_stack*)malloc(sizeof(t_stack));
	result->x = NULL;
	result->length = 0;

	i = 1;
	while (i < len)
	{
		/*
		** converting string parameters to int
		*/
		num = err_atoi(argv[i]);
		/*
		** checking for duplicates in stack
		*/
		find_duplicates(result, num);
		/*
		** creating stack element
		*/
		elem = (t_elem*)malloc(sizeof(t_elem));
		elem->up = NULL;
		elem->down = NULL;
		elem->value = num;
		elem->portion_index = 0;

		push_back(result, elem);
		i++;
	}
	return result;
}