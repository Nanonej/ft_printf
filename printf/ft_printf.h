/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:24 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/04 15:27:09 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> ////////////////////////////////////////////////////////////

typedef struct	s_opt
{
	char		minus;
	char		plus;
	char		zero;
	char		space;
	char		hash;
	int			len;
	int			prec;
	char		*mod;
	char		*conv;
}				t_opt;

int		ft_printf(const char *format, ...);

#endif
