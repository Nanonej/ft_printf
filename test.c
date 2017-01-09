/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:10:29 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/09 10:51:00 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>
#include <locale.h>

int		main(void)
{
	ft_printf("test %s", "de merde.");
	return (0);
}

// printf("Minus : %c\n", form->minus);
// printf("Plus : %c\n", form->plus);
// printf("Zero : %c\n", form->zero);
// printf("Space : %c\n", form->space);
// printf("hash : %c\n", form->hash);
// printf("len : %d\n", form->len);
// printf("prec : %d\n", form->prec);
// printf("mod : %s\n", form->mod);
// printf("conv : %c\n", form->conv);
