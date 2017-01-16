/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:10:29 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/16 11:25:17 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*join_part(char *dec, int tenth, int prec, char sign)
{
	char		*stenth;
	char		*tmp;
	int			i;
	int			j;

	i = prec - i;
	if (!(stenth = ft_strnew(prec)))
		return (NULL);
	stenth = (char *)ft_memset(stenth, '0', prec);
	if (!(tmp = ft_itoa_base(tenth, 10, 0)))
		return (NULL);
	j = (int)ft_strlen(tmp) - 1;
	while (j > -1)
		stenth[i--] = tmp[j--];
	free(tmp);
	if (!(tmp = ft_strjoin(dec, stenth)))
		return (NULL);
	free(stenth);
	return (tmp);
}

char			*ft_dtoa(long double d, int prec, char sign)
{
	int			i;
	int			dec;
	int			tenth;
	char		*ret;
	char		*sdec;

	i = prec;
	dec = (int)d;
	d -= (long double)dec;
	while (i-- > 0)
		d *= 10;
	tenth = (int)d;
	d -= ((long double)tenth + 0.4);
	if (d > 0)
		tenth++;
	if (!(ret = ft_itoa_base(dec, 10, sign)))
		return (NULL);
	if (!(sdec = ft_strjoin(ret, ".")))
		return (NULL);
	free(ret);
	ret = join_part(sdec, tenth, prec, sign);
	if (!ret)
		return (NULL);
	free(sdec);
	return (ret);
}
