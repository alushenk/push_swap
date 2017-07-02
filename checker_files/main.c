//
// Created by Anton Lushenko on 6/30/17.
//

#include "../src/push_swap.h"

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
		{
			ft_putstr("checker atoi function \n");
			error_wrong_arguments();
		}
		str++;
	}
	if (*str != '\0' && ft_isdigit(*str) == 0)
	{
		if (*str == '\n')
			*stop = 1;
		else
		{
			ft_putstr("checker atoi function \n");
			error_wrong_arguments();
		}
	}
	return (int)result * sign;
}

void	perform(t_stack *a, t_stack *b, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		sa(a);
	else if (ft_strcmp(command, "sb") == 0)
		sb(b);
	else if (ft_strcmp(command, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(command, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(command, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(command, "ra") == 0)
		ra(a);
	else if (ft_strcmp(command, "rb") == 0)
		rb(b);
	else if (ft_strcmp(command, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(command, "rra") == 0)
		rra(a);
	else if (ft_strcmp(command, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(a, b);
	else
	{
		//ft_putstr(command);
		ft_putstr("suka");
		error_wrong_arguments();
	}
}

int main(int argc, char **argv)
{
	int stop;
	int num;
	size_t i;
	t_stack *stack;
	t_stack *sorted_stack;
	t_stack *buffer;
	t_elem *elem;
	char *str;

	g_instructions = create_list();

	stack = create_stack();
	buffer = create_stack();

	stop = 0;
	if (argc > 1)
	{
		i = 1;
		while ((int)i < argc && stop == 0)
		{
			num = checker_atoi(argv[i], &stop);
			find_duplicates(stack, num);
			elem = create_element(num);
			push_back(stack, elem);
			i++;
		}
		display_stack(stack);
		sorted_stack = insertion_sort(stack);
		while (get_next_line(0, &str) == 1)
			perform(stack, buffer, str);
		i = 0;
		display_both(stack, sorted_stack);
		while (i < sorted_stack->length)
		{
			if (stack->x->value != sorted_stack->x->value)
				error_sorting();
			rr(stack, sorted_stack);
			i++;
		}
		display_both(stack, sorted_stack);
		ft_putstr("OK!\n");
	}
	else
		error_no_arguments();
}