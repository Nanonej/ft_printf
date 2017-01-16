/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:30:34 by lchim             #+#    #+#             */
/*   Updated: 2017/01/13 15:32:39 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			check_alloc(void *ptr)
{
	if (!ptr)
	{
		ft_putendl("Memory Allocation Failed.");
		exit(EXIT_FAILURE);
	}
}

int				check_conv(char c)
{
	if (ft_strfind("sSpdDioOuUxXcCbBfF%", c) == -1)
		return (0);
	return (1);
}

void			check_conv_mod(t_form *form, char *mod)
{
	if (ft_strlen(mod) == 1)
		form->mod = ft_strfind("ahlLjz", *mod);
	else if (ft_strlen(mod) == 2 && ft_strequ("ll", mod))
		form->mod = LL;
	else if (ft_strlen(mod) == 2 && ft_strequ("hh", mod))
		form->mod = HH;
	else
		form->mod = J;
}

void			free_swap(char **src, char *dst)
{
	free(*src);
	*src = dst;
}
