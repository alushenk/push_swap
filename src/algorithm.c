//
// Created by Anton Lushenko on 6/26/17.
//

#include "push_swap.h"

// sorts top two elements of stack
void		sort_two_ascending(t_stack *stack)
{
	int one;
	int two;

	one = stack->x->value;
	two = stack->x->down->value;

	if (one > two)
		swap(stack);
}

void		sort_two_descending(t_stack *stack)
{
	int one;
	int two;

	one = stack->x->value;
	two = stack->x->down->value;

	if (one < two)
		swap(stack);
}

void 		case_0(t_stack *stack)
{
	swap(stack);
	rotate_up(stack);
	swap(stack);
	rotate_down(stack);
	swap(stack);
}

void		case_1(t_stack *stack)
{
	swap(stack);
	rotate_up(stack);
	swap(stack);
	rotate_down(stack);
}

void 		case_2(t_stack *stack)
{
	rotate_up(stack);
	swap(stack);
	rotate_down(stack);
	swap(stack);
}

void		case_3(t_stack *stack)
{
	swap(stack);
}

void		case_4(t_stack *stack)
{
	rotate_up(stack);
	swap(stack);
	rotate_down(stack);
}

// sorts top three elements of stack
void		sort_three_ascending(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->x->value;
	b = stack->x->down->value;
	c = stack->x->down->down->value;

	if (a > b > c)
		case_0(stack);
	else if (a > c > b)
		case_1(stack);
	else if (b > a > c)
		case_2(stack);
	else if (c > a > b)
		case_3(stack);
	else if (b > c > a)
		case_4(stack);
}

void		sort_three_descending(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->x->value;
	b = stack->x->down->value;
	c = stack->x->down->down->value;

	if (a < b < c)
		case_0(stack);
	else if (a < c < b)
		case_1(stack);
	else if (b < a < c)
		case_2(stack);
	else if (c < a < b)
		case_3(stack);
	else if (b < c < a)
		case_4(stack);
}

// sorting in ascending order
void		sort_a(t_stack *stack)
{
	if (stack->length == 2)
		sort_two_ascending(stack);
	else if (stack->length == 3)
		sort_three_ascending(stack);
}

int			get_group_length(t_stack *stack, int group)
{
	int len;
	t_elem *temp;

	len = 0;
	temp = stack->x;
	while (temp->group == group)
	{
		len += 1;
		temp = temp->down;
	}
	return len;
}

// sorting in descending order
void 		sort_b(t_stack *stack, int group)
{
	if (stack->length == 2)
		sort_two_descending(stack);
	else if (stack->length == 3)
		sort_three_descending(stack);
}

void		split_stack(t_stack *stack, int group)
{

}

t_stack		*quicksort(t_stack *stack, int *sorted_array)
{
	int median;
	int i;
	int group;
	int half;
	int sorted_stack_length;
	t_stack *buffer;

	buffer = create_stack();

	sorted_stack_length = stack->length;
	group = 1;
	// splitting stack into groups
	while (stack->length > 3)
	{
		half = sorted_stack_length - stack->length / 2;
		median = sorted_array[half];
		i = 0;
		while (i < stack->length)
		{
			if (stack->x->value < median)
			{
				stack->x->group = group;
				replace(stack, buffer);
			}
			else
			{
				rotate_up(stack);
				i++;
			}
		}
		display_both(stack, buffer);
		ft_putchar('\n');
		group += 1;
	}
	// sorting by groups
	if (get_group_length(stack, 0) <= 3)
	{
		sort_a(stack);
	}
	else
	{
		
	}
	if (get_group_length(buffer, group) <= 3)
	{
		sort_b(stack, group);
		group -= 1;
	}
	else
	{

	}


	return NULL;
}