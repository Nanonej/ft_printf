/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:10:29 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/11 12:03:19 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*dtoa(double c, char sign)
{
	int		i;
	int		tmp;
	char	*ent;
	char	*ret;

	i = (int)c;
	c -= (double)i;
	while (c != (double)(tmp = (int)c))
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
