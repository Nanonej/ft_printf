/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:28:21 by lchim             #+#    #+#             */
/*   Updated: 2017/01/05 14:03:34 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_alloc(void *ptr)
{
	if (!ptr)
	{
		ft_putendl_fd("Memory allocation failed.", 2);
		exit(EXIT_FAILURE);
	}
}

int		check_conv(char c)
{
	if (ft_strfind("sSpdDioOuUxXcC%", c) == -1)
		return (1);
	return (0);
}
