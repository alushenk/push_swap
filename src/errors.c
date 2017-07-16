/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:31:30 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/06 17:31:32 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_wrong_arguments(void)
{
	ft_putstr("Error! Wrong arguments\n");
	exit(0);
}

void	error_duplicates(void)
{
	ft_putstr("Error! There are duplicates\n");
	exit(0);
}

void	error_no_arguments(void)
{
	ft_putstr("Error! No arguments found\n");
	exit(0);
}

void	error_opening_file(void)
{
	ft_putstr("Error! Cannot open file\n");
	exit(0);
}

void	error_sorting(void)
{
	ft_putstr("KO!\n");
	exit(0);
}
