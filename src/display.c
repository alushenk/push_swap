//
// Created by Anton Lushenko on 6/24/17.
//

#include "push_swap.h"

void	display_stack(t_stack *stack)
{
	size_t i;

	i = 0;
	while (i < stack->length)
	{
		ft_putstr(ft_itoa(stack->x->value));
		ft_putchar('\n');
		rotate_up(stack);
		i++;
	}
}

void	display_array(int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(array[i]);
		ft_putchar('\n');
		i++;
	}
}