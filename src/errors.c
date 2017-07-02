//
// Created by lush on 6/25/17.
//

#include "push_swap.h"

void    error_wrong_arguments()
{
    ft_putstr("Error! Wrong arguments\n");
    exit(0);
}

void    error_duplicates()
{
    ft_putstr("Error! There are duplicates\n");
    exit(0);
}

void    error_no_arguments()
{
    ft_putstr("Error! No arguments found\n");
    exit(0);
}

void	error_memory_allocation()
{
	ft_putstr("Error! Cannot allocate memory\n");
	exit(0);
}

void	error_sorting()
{
	ft_putstr("KO!\n");
	exit(0);
}