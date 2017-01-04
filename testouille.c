/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testouille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:53:50 by lchim             #+#    #+#             */
/*   Updated: 2017/01/04 19:13:17 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <stdio.h>
int				main(void)
{
	t_opt		form_arg;
	char		*format;
	char		*buff;
	int			i;

	i = 0;
	buff = ft_strnew(0);
	format = ft_strdup("coucou%+- 012.53ssalut les amis%dmerde");
	buff = buff_until(buff, format, &i);
	printf("BUFF 1 : %s\n", buff);
	start_opt(&form_arg, format, &i);
	free(buff);
	buff = buff_until(buff, format, &i);
	printf("BUFF 2 : %s\n", buff);
	start_opt(&form_arg, format, &i);
	buff = buff_until(buff, format, &i);
	printf("Minus : %c\n", form_arg.minus);
	printf("Plus : %c\n", form_arg.plus);
	printf("Zero : %c\n", form_arg.zero);
	printf("Space : %c\n", form_arg.space);
	printf("Hash : %c\n", form_arg.hash);
	printf("Len : %d\n", form_arg.len);
	printf("Prec : %d\n", form_arg.prec);
	printf("Mod : %s\n", form_arg.mod);
	printf("Conv : %c\n", form_arg.conv);
	printf("BUFF 3 : %s\n", buff);
	return (0);
}
