/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:10:29 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/07 14:16:55 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>
#include <locale.h>

int		main(void)
{
	int			a = 42;
	void		*b = &a;

	setlocale(LC_ALL, "en_US");

	printf("\nTest 00 - %%%%\n");

	printf("Test 01 - %%s: %s\n", "OK");
	printf("Test 02 - %%S: %S\n", L"アニメ");
	printf("Test 03 - %%p: %p\n", b);
	printf("Test 04 - %%d: %d\n", a);
	printf("Test 05 - %%D: %D\n", a);
	printf("Test 06 - %%i: %i\n", a);
	printf("Test 07 - %%o: %o\n", 34);
	printf("Test 08 - %%O: %O\n", 34);
	printf("Test 09 - %%u: %u\n", (unsigned int)4200000000);
	printf("Test 10 - %%U: %U\n", (unsigned int)4200000000);
	printf("Test 11 - %%x: %x\n", 42);
	printf("test 12 - %%X: %X\n", 42);
	printf("Test 13 - %%c: %c\n", 42);
	printf("Test 14 - %%C: %C\n", L'ア');

	printf("Test 15 - %%#o: %#o\n", 34);
	printf("Test 16 - %%#x: %#x\n", 42);
	printf("Test 17 - %%#X: %#X\n", 42);

	printf("Test 18 - %%08d: %08d\n", 42);
	printf("Test 19 - %%-8d: %-8d\n", 42);
	printf("Test 20 - %%+8d: %+8d\n", 42);
	printf("Test 21 - %% 8d: % 8d\n", 42);

	printf("Test 22 - %%8d: %8d\n", 42);

	printf("Test 23 - %%.2f: %.2f\n", 42.314159265359);

	printf("Test 24 - %%hhd: %hhd\n", (char)'*');
	printf("Test 25 - %%hd: %hd\n", (short)4200);
	printf("Test 26 - %%ld: %ld\n", (long)420000000);
	printf("Test 27 - %%lld: %lld\n", (long long)4223372036854775807);
	printf("Test 28 - %%jd: %jd\n", (intmax_t)42);
	printf("Test 29 - %%zd: %zd\n\n", (size_t)42);

	printf("Test WTF DUDE ?!: %d\n\n", 42);

	return (0);
}
