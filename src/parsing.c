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

int		err_atoi(const char *str)
{
	ssize_t	result;
	int		sign;
	int		is_sign;

	is_sign = 0;
	result = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
	{
		is_sign = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		is_sign = 0;
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || (result * sign < INT_MIN))
			error_wrong_arguments();
		str++;
	}
	if ((*str != '\0' && ft_isdigit(*str) == 0) || is_sign)
		error_wrong_arguments();
	return (int)result * sign;
}

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

char	*ft_strsep(char **str, char sep)
{
	int		i;
	char	*result;

	i = 0;
	while (**str == sep && **str != '\0')
		(*str)++;
	while ((*str)[i] != sep && (*str)[i] != '\0')
		i++;
	if (i == 0)
		return (NULL);
	result = ft_strnew(i);
	ft_strncpy(result, *str, i);
	while ((i-- > 0 || **str == sep) && **str != '\0')
		(*str)++;
	return (result);
}

void	parse(char *arg, t_stack *result)
{
	char	*str;
	t_elem	*elem;
	int		num;

	while ((str = ft_strsep(&arg, ' ')))
	{
		num = err_atoi(str);
		free(str);
		find_duplicates(result, num);
		elem = create_element(num);
		push_back(result, elem);
	}
	if (result->x == NULL)
		error_wrong_arguments();
}

t_stack	*parse_parameters(int len, char **argv)
{
	int		i;
	t_stack	*result;
	int		fd;
	char	*str;

	result = create_stack();
	if (len == 3 && strcmp(argv[1], "-s") == 0)
	{
		if ((fd = open(argv[2], O_RDONLY)) == -1)
		{
			ft_putstr("Error opening file!\n");
			exit(0);
		}
		while (get_next_line(fd, &str))
		{
			parse(str, result);
			free(str);
		}
		close(fd);
		return (result);
	}
	i = 1;
	while (i < len)
	{
		parse(argv[i], result);
		i++;
	}
	return (result);
}
