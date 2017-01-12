/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:30:34 by lchim             #+#    #+#             */
/*   Updated: 2017/01/12 16:16:10 by lchim            ###   ########.fr       */
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
	if (ft_strfind("sSpdDioOuUxXcCbB%eEfF", c) == -1)
		return (0);
	return (1);
}

void			check_conv_mod(t_form *form, char *mod)
{
	if (ft_strlen(mod) == 1)
		form->mod = ft_strfind("ahlLjz", *mod);
	else if (ft_strlen(mod) == 2 && ft_strequ("LL", mod))
		form->mod = LL;
	else if (ft_strlen(mod) == 2 && ft_strequ("HH", mod))
		form->mod = HH;
	else
		form->mod = J;
	if (form->mod == L && ft_strfind("fFeE", form->conv) == -1)
		form->mod = 0;
}

char			*free_swap(char *src, char *dst)
{
	free(src);
	return (dst);
}
