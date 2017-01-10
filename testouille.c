/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testouille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:53:50 by lchim             #+#    #+#             */
/*   Updated: 2017/01/10 13:51:02 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
#include <locale.h>

int				main(void)
{
	setlocale(LC_ALL, "en_US");
	int			a = 42;
	char		b[0];

	// ft_putnbr(ft_printf("Test 00 - %%\n"));
	// ft_putendl("");
	// ft_putnbr(printf("Test 00 - %%\n"));
	// ft_putendl("");
	//
	// ft_putnbr(ft_printf("Test 01 - s: %s\n", "OK"));
	// ft_putendl("");
	// ft_putnbr(printf("Test 01 - s: %s\n", "OK"));
	// ft_putendl("");
	//
	// ft_putnbr(ft_printf("Test 02 - S: %S\n", L"▄︻̷̿┻̿═━一"));
	// ft_putendl("");
	// ft_putnbr(printf("Test 02 - S: %S\n", L"▄︻̷̿┻̿═━一"));
	// ft_putendl("");


	ft_putnbr(ft_printf("Test 03 - p: %p\n", b));
	ft_putendl("");
	ft_putnbr(printf("Test 03 - p: %p\n", b));
	ft_putendl("");


	ft_putnbr(ft_printf("Test 04 - d: %d\n", a));
	ft_putendl("");
	ft_putnbr(printf("Test 04 - d: %d\n", a));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 05 - D: %D\n", a));
	ft_putendl("");
	ft_putnbr(printf("Test 05 - D: %D\n", a));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 06 - i: %i\n", a));
	ft_putendl("");
	ft_putnbr(printf("Test 06 - i: %i\n", a));
	ft_putendl("");


	ft_putnbr(ft_printf("Test 07 - o: %o\n", 34));
	ft_putendl("");
	ft_putnbr(printf("Test 07 - o: %o\n", 34));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 08 - O: %O\n", 34));
	ft_putendl("");
	ft_putnbr(printf("Test 08 - O: %O\n", 34));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 09 - u: %u\n", (unsigned int)4200000000));
	ft_putendl("");
	ft_putnbr(printf("Test 09 - u: %u\n", (unsigned int)4200000000));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 10 - U: %U\n", (unsigned int)4200000000));
	ft_putendl("");
	ft_putnbr(printf("Test 10 - U: %U\n", (unsigned int)4200000000));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 11 - x: %x\n", 42));
	ft_putendl("");
	ft_putnbr(printf("Test 11 - x: %x\n", 42));
	ft_putendl("");

	ft_putnbr(ft_printf("test 12 - X: %X\n", 42));
	ft_putendl("");
	ft_putnbr(printf("test 12 - X: %X\n", 42));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 13 - c: %c\n", 'A'));
	ft_putendl("");
	ft_putnbr(printf("Test 13 - c: %c\n", 'A'));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 14 - C: %C\n", L'腹'));
	ft_putendl("");
	ft_putnbr(printf("Test 14 - C: %C\n", L'腹'));
	ft_putendl("");
	//
	//
	// ft_putnbr(ft_printf("Test 15 - #o: %#o\n", 34));
	// ft_putendl("");
	// ft_putnbr(printf("Test 15 - #o: %#o\n", 34));
	// ft_putendl("");
	//
	// ft_putnbr(ft_printf("Test 16 - #x: %#x\n", 42));
	// ft_putendl("");
	// ft_putnbr(printf("Test 16 - #x: %#x\n", 42));
	// ft_putendl("");
	//
	// ft_putnbr(ft_printf("Test 17 - #X: %#X\n", 42));
	// ft_putendl("");
	// ft_putnbr(printf("Test 17 - #X: %#X\n", 42));
	// ft_putendl("");
	//
	//
	// ft_putnbr(ft_printf("Test 18 - 08d: %08d\n", 42));
	// ft_putendl("");
	// ft_putnbr(printf("Test 18 - 08d: %08d\n", 42));
	// ft_putendl("");
	//
	// ft_putnbr(ft_printf("Test 19 - -8d: %-8d\n", 42));
	// ft_putendl("");
	// ft_putnbr(printf("Test 19 - -8d: %-8d\n", 42));
	// ft_putendl("");
	//
	// ft_putnbr(ft_printf("Test 20 - +8d: %+8d\n", 42));
	// ft_putendl("");
	// ft_putnbr(printf("Test 20 - +8d: %+8d\n", 42));
	// ft_putendl("");
	//
	// ft_putnbr(ft_printf("Test 21 -  8d: % 8d\n", 42));
	// ft_putendl("");
	// ft_putnbr(printf("Test 21 -  8d: % 8d\n", 42));
	// ft_putendl("");
	//
	//
	// ft_putnbr(ft_printf("Test 22 - 8d: %8d\n", 42));
	// ft_putendl("");
	// ft_putnbr(printf("Test 22 - 8d: %8d\n", 42));
	// ft_putendl("");


	// ft_printf("Test 23 - .2f: %.2f\n", 42.314159265359);

	ft_putnbr(ft_printf("Test 24 - hhd: %hhd\n", (char)'*'));
	ft_putendl("");
	ft_putnbr(printf("Test 24 - hhd: %hhd\n", (char)'*'));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 25 - hd: %hd\n", (short)4200));
	ft_putendl("");
	ft_putnbr(printf("Test 25 - hd: %hd\n", (short)4200));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 26 - ld: %ld\n", (long)420000000));
	ft_putendl("");
	ft_putnbr(printf("Test 26 - ld: %ld\n", (long)420000000));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 27 - lld: %lld\n", (long long)4223372036854775807));
	ft_putendl("");
	ft_putnbr(printf("Test 27 - lld: %lld\n", (long long)4223372036854775807));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 28 - jd: %jd\n", (intmax_t)42));
	ft_putendl("");
	ft_putnbr(printf("Test 28 - jd: %jd\n", (intmax_t)42));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 29 - zd: %zd\n", (size_t)42));
	ft_putendl("");
	ft_putnbr(printf("Test 29 - zd: %zd\n", (size_t)42));
	ft_putendl("");


	ft_putnbr(ft_printf("Test 30 - b: %b\n", a));
	ft_putendl("");

	ft_putnbr(ft_printf("Test 31 - B: %B\n", a));
	ft_putendl("");

	// printf("Test WTF DUDE ?!: %d\n\n", 42);

	printf("\n");
	return (0);
}
