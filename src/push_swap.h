//
// Created by Anton Lushenko on 6/24/17.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "../externals/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
# include <limits.h>

typedef struct	s_elem
{
	int value;
	int portion_index;
	struct s_elem *up;
	struct s_elem *down;
}				t_elem;


typedef struct	s_stack
{
	t_elem *x;
	size_t length;
}				t_stack;

/*
** parsing.c
*/
t_stack *parse_parameters(int len, char **argv);
/*
** stack_operations.c
*/
void	push_back(t_stack *stack, t_elem *elem);
void	rotate_up(t_stack *stack);
/*
** display.c
*/
void	display_stack(t_stack *stack);

#endif //PUSH_SWAP_PUSH_SWAP_H
