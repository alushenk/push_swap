/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 17:57:19 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/04 17:57:23 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker_atoi(const char *str, int *stop)
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
	//printf("%s\n", command);
	//display_both(a, b);
	//ft_putchar('\n');
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
		error_wrong_arguments();
}

void	check_sorted(t_stack *stack, t_stack *sorted_stack)
{
	int i;

	i = 0;
	while (i < stack->length)
	{
		if (stack->x->value != sorted_stack->x->value)
		{
			ft_putnbr(stack->x->value);
			ft_putchar('\n');
			error_sorting();
		}
		rr(stack, sorted_stack);
		i++;
	}
}

void	parse_numbers(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		num;
	int		stop;
	t_elem	*elem;

	stop = 0;
	i = 1;
	while (i < argc && stop == 0)
	{
		num = checker_atoi(argv[i], &stop);
		find_duplicates(stack, num);
		elem = create_element(num);
		push_back(stack, elem);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*sorted_stack;
	t_stack	*buffer;
	char	*str;

	if (argc < 2)
		error_no_arguments();
	g_instructions = create_list();
	stack = create_stack();
	buffer = create_stack();
	parse_numbers(argc, argv, stack);
	sorted_stack = insertion_sort(stack);
	while (get_next_line(0, &str) == 1)
		perform(stack, buffer, str);
	display_both(stack, sorted_stack);
	ft_putnbr(g_instructions->length);
	ft_putchar('\n');
	check_sorted(stack, sorted_stack);
	ft_putstr("OK!\n");
}
