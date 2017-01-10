/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:30:34 by lchim             #+#    #+#             */
/*   Updated: 2017/01/10 12:01:01 by lchim            ###   ########.fr       */
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
	if (ft_strfind("sSpdDioOuUxXcCbB%", c) == -1)
		return (0);
	return (1);
}

int				check_conv_mod(t_form *form)
{
	size_t		n;

	if (form->mod)
	{
		n = ft_strlen(form->mod);
		if (form->conv == 'c' && (n > 1 || (form->mod)[0] != 'l'))
			return (0);
		else if (form->conv == 's' && (n > 1 || (form->mod)[0] != 'l'))
			return (0);
	}
	if (ft_strfind("SDOUXCB%", form->conv) != -1 && form->mod)
		return (0);
	return (1);
}

char			*free_swap(char *src, char *dst)
{
	free(src);
	return (dst);
}
