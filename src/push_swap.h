//
// Created by Anton Lushenko on 6/24/17.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "../externals/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_elem
{
	int value;
	struct s_elem *up;
	struct s_elem *down;
}				t_elem;


typedef struct	s_stack
{
	t_elem *start;
	t_elem *end;
	size_t length;
}				t_stack;

/*
** parsing.c
*/
t_list *parse_parameters(int len, char *arguments);
/*
** stack_operations.c
*/
void	push_back(t_stack *stack, t_elem *elem);

#endif //PUSH_SWAP_PUSH_SWAP_H
