/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 00:00:27 by lchim             #+#    #+#             */
/*   Updated: 2017/01/13 23:26:33 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		format_len(t_form *f)
{
	char		*tmp;

	if (f->szarg < f->len)
	{
		check_alloc((tmp = ft_strnew(f->len - f->szarg)));
		tmp = (char *)ft_memset(tmp, ' ', f->len - f->szarg);
		if (!f->minus)
		{
			free_swap(&(f->arg), ft_strjoin(tmp, f->arg));
			check_alloc(f->arg);
		}
		else
		{
			free_swap(&(f->arg), ft_strjoin(f->arg, tmp));
			check_alloc(f->arg);
		}
		f->szarg += ft_strlen(tmp);
		free(tmp);
	}
}

static void		format_hash(t_form *f)
{
	char		*tmp;

	if (ft_strfind("oOxX", f->conv) != -1 && f->hash)
	{
		check_alloc((tmp = ft_strnew(f->hash)));
		if (f->conv == 'o' || f->conv == 'O')
			tmp[0] = '0';
		if (f->conv == 'x' || f->conv == 'X')
			tmp = ft_strcpy(tmp, "0x");
		free_swap(&(f->arg), ft_strjoin(tmp, f->arg));
		free(tmp);
		f->szarg += f->hash;
	}
	if (f->conv == 'X')
	{
		tmp = f->arg;
		while (*tmp)
		{
			*tmp = ft_toupper(*tmp);
			tmp++;
		}
	}
	if (ft_strfind("cC", f->conv) == -1)
		format_len(f);
}

static void		format_sign_d(t_form *f)
{
	char		*tmp;

	if (ft_strfind("dDi", f->conv) != -1 && (f->plus || f->space || f->sign))
	{
		check_alloc((tmp = ft_strdup(" ")));
		if (f->plus)
			tmp[0] = '+';
		if (f->sign)
			tmp[0] = '-';
		free_swap(&(f->arg), ft_strjoin(tmp, f->arg));
		free(tmp);
		f->szarg++;
	}
	format_hash(f);
}

void			format_prec(t_form *f)
{
	char		*tmp;

	if (f->prec > f->szarg && ft_strfind("dDiuUoOxXbB", f->conv) != -1)
	{
		f->prec -= f->szarg;
		check_alloc((tmp = ft_strnew(f->prec)));
		tmp = (char *)ft_memset(tmp, '0', f->prec);
		free_swap(&(f->arg), ft_strjoin(tmp, f->arg));
		check_alloc(f->arg);
		f->szarg += f->prec;
		free(tmp);
	}
	format_sign_d(f);
}
