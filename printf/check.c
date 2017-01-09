/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:30:34 by lchim             #+#    #+#             */
/*   Updated: 2017/01/09 16:30:55 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			check_alloc(void *ptr)
{
	if (!ptr)
		exit(EXIT_FAILURE);
}

int				check_conv(char c)
{
	if (ft_strfind("sSpdDioOuUxXcC%", c) == -1)
		return (1);
	return (0);
}

char			*free_swap(char *forfree, char *tochange)
{
	free(forfree);
	return (tochange);
}
