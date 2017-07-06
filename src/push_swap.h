/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:42:13 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 19:42:15 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "../externals/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <limits.h>

typedef struct		s_elem
{
	int				value;
	int				group_length;
	struct s_elem	*up;
	struct s_elem	*down;
}					t_elem;

typedef struct		s_stack
{
	t_elem			*x;
	int				length;
}					t_stack;

typedef struct		s_array
{
	int				*array;
	int				length;
}					t_array;

typedef struct		s_inst
{
	char			*name;
	struct s_inst	*next;
	struct s_inst	*prev;
}					t_inst;

typedef struct		s_inst_lst
{
	t_inst			*x;
	int				length;
}					t_inst_lst;

t_inst_lst			*g_instructions;

/*
** parsing.c
*/
t_stack				*parse_parameters(int len, char **argv);
void				find_duplicates(t_stack *stack, int num);
/*
** stack_operations.c
*/
void				push(t_stack *stack, t_elem *elem);
void				push_back(t_stack *stack, t_elem *elem);
void				rotate_up(t_stack *stack);
void				rotate_down(t_stack *stack);
t_stack				*create_stack();
t_elem				*create_element(int value);
void				replace(t_stack *a, t_stack *b);
t_elem				*pop(t_stack *stack);
t_stack				*copy_stack(t_stack *stack);
void				swap(t_stack *stack);
/*
** display.c
*/
void				display_stack(t_stack *stack);
void				display_instructions(t_inst_lst *stack);
void				display_array(t_array *array);
void				display_both(t_stack *a, t_stack *b);
/*
** errors.c
*/
void				error_wrong_arguments();
void				error_duplicates();
void				error_no_arguments();
void				error_memory_allocation();
void				error_sorting();
/*
** simple_sorting.c
*/
t_stack				*insertion_sort(t_stack *stack_to_sort);
t_array				*create_array(t_stack *stack);
/*
** algorithm.c
*/
void				quicksort(t_stack *a, t_stack *b, t_array *sorted_array);
void				sort_a(t_stack *stack, int length);
void				sort_b(t_stack *stack, int length);
void				replace_group(t_stack *a, t_stack *b, int group_length);
/*
** split_functions.c
*/
void				split_a_first(t_stack *a, t_stack *b, int median);
void				split_b(t_stack *a, t_stack *b, int median, int init_len);
void				split_a(t_stack *a, t_stack *b, int median, int init_len);
/*
** cases.c
*/
void				case_0(t_stack *stack);
void				case_1(t_stack *stack);
void				case_2(t_stack *stack);
void				case_3(t_stack *stack);
void				case_4(t_stack *stack);
/*
** three_two_sortings.c
*/
void				sort_two_ascending(t_stack *stack);
void				sort_two_descending(t_stack *stack);
void				sort_three_ascending(t_stack *stack);
void				sort_three_descending(t_stack *stack);
/*
** wrappers.c
*/
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *a, t_stack *b);
/*
** simultaneous_sort.c
*/
void				simultaneous_sort(t_stack *a, t_stack *b);
/*
** instructions.c
*/
t_inst_lst			*create_list();
t_inst				*create_instruction(char *name);
void				add_instruction(t_inst_lst *list, char *name);
void				free_list(t_inst_lst *list);
void				insert_instruction(t_inst_lst *list, t_inst *instruction);

#endif
