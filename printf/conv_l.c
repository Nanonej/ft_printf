/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:58:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/07 11:28:16 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_s(char *buff, va_list ap, t_opt form_arg)
{
	char	*tmp;

	if (form_arg.conv)
	{
		tmp = buff;
		buff = ft_strjoin(buff, va_arg(ap, char *));
		check_alloc((void *)buff);
		free(tmp);
	}
	return (buff);
}
