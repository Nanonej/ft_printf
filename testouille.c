/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testouille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:53:50 by lchim             #+#    #+#             */
/*   Updated: 2017/01/05 14:00:05 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <stdio.h>
int				main(void)
{
	char		*format;
	char		*buff;
	t_opt		form_arg;
	int			i;
	int			n;

	i = 1;
	buff = ft_strnew(0);
	format = ft_strdup("test d%#-+ hhe mer%sde%d");
	while (*format)
	{
		buff = buff_until(buff, &format);
		printf("NOTCONV %d : %s\n", i, buff);
		if (*(format - 1) == '%')
		{
			n = start_opt(&form_arg, &format);
			printf("RET : %d\n", n);
			printf("MINUS  %d : %c\n", i, form_arg.minus);
			printf("PLUS  %d : %c\n", i, form_arg.plus);
			printf("ZERO  %d : %c\n", i, form_arg.zero);
			printf("SPACE  %d : %c\n", i, form_arg.space);
			printf("hash  %d : %c\n", i, form_arg.hash);
			printf("LEN  %d : %d\n", i, form_arg.len);
			printf("PREC  %d : %d\n", i, form_arg.prec);
			printf("MOD  %d : %s\n", i, form_arg.mod);
			printf("CONV  %d : %c\n", i, form_arg.conv);
		}
		i++;
		printf("--------------------------");
	}
	return (0);
}
