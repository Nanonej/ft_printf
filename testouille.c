/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testouille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:53:50 by lchim             #+#    #+#             */
/*   Updated: 2017/01/04 16:15:43 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int				main(void)
{
	t_opt		form_arg;
	int			i = 0;

	clear_t_opt(&form_arg);
	fill_t_opt(&form_arg, ".42", &i);
	printf("Minus : %c\n", form_arg.minus);
	printf("Plus : %c\n", form_arg.plus);
	printf("Zero : %c\n", form_arg.zero);
	printf("Space : %c\n", form_arg.space);
	printf("Hash : %c\n", form_arg.hash);
	printf("Len : %d\n", form_arg.len);
	printf("Prec : %d\n", form_arg.prec);
	return (0);
}
