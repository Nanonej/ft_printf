/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testouille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:53:50 by lchim             #+#    #+#             */
/*   Updated: 2017/01/04 18:33:06 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <stdio.h>
int				main(void)
{
	t_opt		form_arg;
	int			i = 0;

	start_opt(&form_arg, "0 +-5654.23hs", &i);
	printf("Minus : %c\n", form_arg.minus);
	printf("Plus : %c\n", form_arg.plus);
	printf("Zero : %c\n", form_arg.zero);
	printf("Space : %c\n", form_arg.space);
	printf("Hash : %c\n", form_arg.hash);
	printf("Len : %d\n", form_arg.len);
	printf("Prec : %d\n", form_arg.prec);
	printf("Mod : %s\n", form_arg.mod);
	printf("Conv : %c\n", form_arg.conv);
	return (0);
}
