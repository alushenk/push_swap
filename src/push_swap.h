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
	int group;
	struct s_elem *up;
	struct s_elem *down;
}				t_elem;


typedef struct	s_stack
{
	t_elem *x;
	int length;
}				t_stack;

/*
** parsing.c
*/
t_stack *parse_parameters(int len, char **argv);
/*
** stack_operations.c
*/
void 	push(t_stack *stack, t_elem *elem);
void	push_back(t_stack *stack, t_elem *elem);
void	rotate_up(t_stack *stack);
void	rotate_down(t_stack *stack);
t_stack	*create_stack();
t_elem *create_element(int value);
void	replace(t_stack *a, t_stack *b);
t_elem	*pop(t_stack *stack);
t_stack	*copy_stack(t_stack *stack);
void	swap(t_stack *stack);
/*
** display.c
*/
void	display_stack(t_stack *stack);
void	display_array(int *array, int len);
void	display_both(t_stack *a, t_stack *b);
/*
** errors.c
*/
void    error_wrong_arguments();
void    error_duplicates();
void    error_no_arguments();
/*
** simple_sorting.c
*/
t_stack		*insertion_sort(t_stack *stack_to_sort);
int 	*create_array(t_stack *stack);
/*
** algorithm.c
*/
t_stack		*quicksort(t_stack *stack, int *sorted_array);

#endif //PUSH_SWAP_PUSH_SWAP_H
