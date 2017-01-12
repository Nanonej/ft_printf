/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 00:00:27 by lchim             #+#    #+#             */
/*   Updated: 2017/01/12 15:10:14 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static void		format_len(t_form *form)
{
	int			i;
	char		*tmp;

	i = (int)ft_strlen(form->arg);
	if (i < form->len)
	{
		tmp = ft_strnew(form->len - i);
		check_alloc((void *)tmp);
		tmp = (char *)ft_memset(tmp, ' ', form->len - i);
		if (!form->minus)
		{
			if(form->minus)
				printf("POUET\n");
			form->arg = free_swap(form->arg, ft_strjoin(tmp, form->arg));
			check_alloc((void *)form->arg);
		}
		else
		{
			form->arg = free_swap(form->arg, ft_strjoin(form->arg, tmp));
			check_alloc((void *)form->arg);
		}
		free(tmp);
	}
}

static void		format_hash(t_form *form)
{
	if ((ft_strfind("oOxX", form->conv) != -1 && form->hash) || \
	form->conv == 'p')
	{
		if ((form->conv == 'o' || form->conv == 'O') && form->arg[0] != '0')
		{
			form->arg = free_swap(form->arg, ft_strjoin("0", form->arg));
			check_alloc((void *)form->arg);
		}
		else
		{
			form->arg = free_swap(form->arg, ft_strjoin("0x", form->arg));
			check_alloc((void *)form->arg);
			if (form->conv == 'X')
				form->arg[1] = 'X';
		}
	}
	format_len(form);
}

static void		format_plus_space(t_form *form)
{
	if (ft_strfind("dDi", form->conv) != -1)
	{
		if (form->plus)
		{
			form->arg = free_swap(form->arg, ft_strjoin("+", form->arg));
			check_alloc((void *)form->arg);
		}
		else if (form->space)
		{
			form->arg = free_swap(form->arg, ft_strjoin(" ", form->arg));
			check_alloc((void *)form->arg);
		}
	}
	format_hash(form);
}

void			format_zero_prec(t_form *form)
{
	int			i;
	char		*tmp;

	i = (int)ft_strlen(form->arg);
	if (ft_strfind("cC", form->conv) != -1)
		form->prec = -1;
	if (form->prec == -1 && form->zero && !(form->minus))
		form->prec = form->len;
	if (i < form->prec)
	{
		tmp = ft_strnew(form->prec - i);
		check_alloc((void *)tmp);
		tmp = (char *)ft_memset(tmp, '0', form->prec - i);
		form->arg = free_swap(form->arg, ft_strjoin(tmp, form->arg));
		check_alloc((void *)form->arg);
		free(tmp);
	}
	format_plus_space(form);
}
