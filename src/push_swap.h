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
	int group_length;
	struct s_elem *up;
	struct s_elem *down;
}				t_elem;


typedef struct	s_stack
{
	t_elem *x;
	int length;
}				t_stack;

typedef struct	s_array
{
	int *array;
	int length;
}				t_array;

typedef struct	s_instruction
{
	char *name;
	struct s_instruction *next;
	struct s_instruction *prev;
}				t_instruction;

typedef struct	s_instructions
{
	t_instruction *x;
	int length;
}				t_instructions;

t_instructions	*g_instructions;

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
void	display_instructions(t_instructions *stack);
void	display_array(t_array *array);
void	display_both(t_stack *a, t_stack *b);
/*
** errors.c
*/
void    error_wrong_arguments();
void    error_duplicates();
void    error_no_arguments();
void	error_memory_allocation();
/*
** simple_sorting.c
*/
t_stack		*insertion_sort(t_stack *stack_to_sort);
t_array 	*create_array(t_stack *stack);
/*
** algorithm.c
*/
t_stack		*quicksort(t_stack *stack, t_stack *buffer, t_array *sorted_array);
/*
** cases.c
*/
void 		case_0(t_stack *stack);
void 		case_1(t_stack *stack);
void 		case_2(t_stack *stack);
void 		case_3(t_stack *stack);
void 		case_4(t_stack *stack);
/*
** three_two_sortings.c
*/
void		sort_two_ascending(t_stack *stack);
void		sort_two_descending(t_stack *stack);
void		sort_three_ascending(t_stack *stack);
void		sort_three_descending(t_stack *stack);
/*
** wrappers.c
*/
t_instructions	*create_list();
t_instruction	*create_instruction(char *name);
void			add_instruction(char *name);
void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *a, t_stack *b);

#endif //PUSH_SWAP_PUSH_SWAP_H
