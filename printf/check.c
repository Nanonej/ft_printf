/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:30:34 by lchim             #+#    #+#             */
/*   Updated: 2017/01/16 12:58:31 by aridolfi         ###   ########.fr       */
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

int				check_wchar(wchar_t c)
{
	if (c <= 0x10FFFF)
	{
	    if (c <= 0x7F)
	        return (1);
	    else if (c < 0x7FF)
	        return (2);
	    else if (c < 0xFFFF)
	        return (3);
	    else
	        return (3);
	}
	return (-1);
}

void			free_swap(char **src, char *dst)
{
	free(*src);
	*src = dst;
}
