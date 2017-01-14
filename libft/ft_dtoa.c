/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:10:29 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/14 11:49:41 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*part_ent(long double d, char sign)
{
	char			*tmp;
	char			*ret;
	long long		i;

	i = (long long int)d;
	tmp = ft_itoa_base(d, 10, sign);
	if (!tmp)
		return (tmp);
	ret = ft_strjoin(tmp, ".");
	if (!ret)
		return (ret);
	free(tmp);
	return (ret);
}

char				*ft_dtoa(long double d, int prec, char sign)
{
	char			*tenth;
	char			*tmp;
	char			*ret;
	long long int	i;

	if (!(ret = part_ent(d, sign)))
		return (ret);
	i = (long long int)d;
	d -= (long double)i;
	while (prec-- > 0)
		d *= 10;
	i = (long long int)d;
	d -= (long double)i;
	if (d >= 0.5 && d < 1)
		i++;
	if (!(tenth = ft_itoa_base(i, 10, 0)))
		return (tenth);
	tmp = ret;
	if (!(ret = ft_strjoin(dec, tenth)))
		return (NULL);
	free(tmp);
	free(tenth);
	return (ret);
}
