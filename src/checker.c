//
// Created by Anton Lushenko on 6/30/17.
//

#include "push_swap.h"

int	checker_atoi(const char *str, int *stop)
{
	ssize_t	result;
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

void	perform(t_stack *a, t_stack *b, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		sa(a);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(command, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(b);
	else
		error_wrong_arguments();
}

int main(int argc, char **argv)
{
	int stop;
	int num;
	int i;
	t_stack *stack;
	t_stack *buffer;
	t_elem *elem;
	char *str;

	g_instructions = (t_instructions*)malloc(sizeof(t_instructions));
	g_instructions->length = 0;

	stack = create_stack();
	buffer = create_stack();

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
		while (get_next_line(0, &str))
		{

			perform(stack, buffer, str);
			i++;
		}
	}
	else
		error_no_arguments();
}