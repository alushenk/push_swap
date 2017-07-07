/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:45:05 by alushenk          #+#    #+#             */
/*   Updated: 2017/07/07 15:45:06 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		rename_command(char *name)
{
	if (ft_strcmp(name, "sa") == 0)
		name[1] = 's';
	else if (ft_strcmp(name, "ra") == 0)
		name[1] = 'r';
	else if (ft_strcmp(name, "rra") == 0)
		name[2] = 'r';
}

void		rename_command_b(char *name)
{
	if (ft_strcmp(name, "sa") == 0)
		name[1] = 'b';
	else if (ft_strcmp(name, "ra") == 0)
		name[1] = 'b';
	else if (ft_strcmp(name, "rra") == 0)
		name[2] = 'b';
}
