/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:56:19 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/09 18:35:35 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ndigit_to_alloc(int n, int base)
{
	int ret;

	ret = 0;
	while (n)
	{
		n /= base;
		ret++;
	}
	return (ret);
}

char			*ft_itoa_base(int n, int base)
{
	char	*new;
	char	tab[17];
	size_t	dc;
	size_t	i;

	dc = 0;
	i = 1;
	if (n == 0)
		return (ft_strdup("0"));
	ft_strcpy(tab, "0123456789abcdef");
	dc = ft_ndigit_to_alloc(n, base);
	if (!(new = ft_strnew(dc)))
		return (NULL);
	while (n)
	{
		new[dc - i++] = tab[n % base];
		n /= base;
	}
	return (new);
}
