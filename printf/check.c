/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:30:34 by lchim             #+#    #+#             */
/*   Updated: 2017/01/11 12:35:56 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			check_alloc(void *ptr)
{
	if (!ptr)
		exit(EXIT_FAILURE);
}

int				check_conv(char c)
{
	if (ft_strfind("sSpdDioOuUxXcCbB%eEfF", c) == -1)
		return (0);
	return (1);
}

void			check_conv_mod(t_form *form)
{
	if (form->conv == 'c')
	{
		if (ft_strfind(form->mod, 'l') != -1 && !ft_strequ(form->mod, "ll"))
		{
			form->mod = free_swap(form->mod, ft_strdup("l"));
			check_alloc((void *)form->mod);
		}
		else
		{
			free(form->mod);
			form->mod = NULL;
		}
	}
	else
	{
		if (ft_strlen(form->mod) >= 2 && !ft_strequ(form->mod, "ll") && \
		!ft_strequ(form->mod, "hh"))
		{
			form->mod = free_swap(form->mod, ft_strdup("j"));
			check_alloc((void *)form->mod);
		}
	}
}

char			*free_swap(char *src, char *dst)
{
	free(src);
	return (dst);
}
