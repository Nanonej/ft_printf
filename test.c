/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:10:29 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/11 11:13:04 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>
#include <locale.h>

char		*dtoa(double c, char sign)
{
	int		i;
	int		tmp;
	char	*ent;
	char	*ret;

	i = (int)c;
	c -= (double)i;
	while (c != (double)(tmp = (int) c))
		c *= 10;
	ent = ft_strjoin(ft_itoa_base(i, 10, sign), ".");
	if (ent == NULL)
		return (NULL);
	ret = ft_strjoin(ent, ft_itoa(c));
	if (ret == NULL)
		return (NULL);
	free(ent);
	return (ret);
}

int			main(void)
{
	double	c;

	c = -1.99999999;
	ft_putstr(dtoa(c > 0 ? c : -c, c > 0 ? 0 : 1));
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
