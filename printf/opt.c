/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:09:44 by lchim             #+#    #+#             */
/*   Updated: 2017/01/07 14:27:27 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*opt_plus_space(char *arg, char plus, char space)
{
	char	*tmp;

	tmp = NULL;
	if (space || plus)
	{
		tmp = ft_strjoin(" ", arg);
		check_alloc((void *)tmp);
	}
	if (plus)
		tmp[0] = '+';
	free(arg);
	return (tmp);
}

char		*opt_len(char *arg, int len, char minor, char zero)
{
	char	*tmp;

	tmp = ft_strnew(len);
	check_alloc((void *)tmp);
	if (!minor && zero)
		tmp = (char *)ft_memset((void *)tmp, '0', len);
	else
		tmp = (char *)ft_memset((void *)tmp, ' ', len);
	if (minor)
		tmp = ft_strcpy(tmp, arg);
	else
		tmp = ft_strcpy(tmp + (ft_strlen(tmp) - ft_strlen(arg)), arg);
	free(arg);
	return (tmp);
}

char		*opt_prec(char *arg, int prec)
{
	char	*tmp;

	ft_strclr(arg + ft_strfind(arg, '.') + prec + 2);
	if (arg[ft_strlen(arg) - 1] > '5' && arg[ft_strlen(arg) - 1] < '9')
		arg[ft_strlen(arg) - 2] += 1;
	arg[ft_strlen(arg) - 1] = '\0';
	tmp = ft_strdup(arg);
	check_alloc((void *)tmp);
	free(arg);
	return (tmp);
}
