//
// Created by Anton Lushenko on 6/30/17.
//

#include "push_swap.h"

int	checker_atoi(const char *str, int *stop)
{
	size_t	result;
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
	{
		if (*str == '\n')
			*stop = 1;
		else
			error_wrong_arguments();
	}
	return (int)result * sign;
}

int main(int argc, char **argv)
{
	int stop;
	int num;
	int i;
	t_stack *stack;
	t_elem *elem;
	t_instructions *instructions;
	t_instruction *instruction;

	stack = create_stack();

	instructions = create_list();

	stop = 0;
	if (argc > 1)
	{
		i = 1;
		while (i < argc && stop == 0)
		{
			num = checker_atoi(argv[i], &stop);
			find_duplicates(stack, num);
			elem = create_element(num);
			push_back(stack, elem);
			i++;
		}
		while (i < argc)
		{

			i++;
		}
	}
	else
		error_no_arguments();
}