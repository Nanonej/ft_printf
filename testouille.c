/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testouille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:53:50 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/16 11:29:10 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <fcntl.h>
#include <locale.h>

void 		check_error(int	i)
{
	if (i != 0)
	{
		ft_putendl("ERROR DIFF");
		exit(EXIT_FAILURE);
	}
}

int			main(void)
{
	setlocale(LC_ALL, "en_US");
	int			a = 42;
	char		b[0];
	int			i;

	ft_putendl("Test 00 - %:");
	i = ft_printf("ft_printf: %14%\n");
	i -= printf("printf: %14%\n");
	printf("Diff RET: %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	// ft_putendl("Test 02 - %s:");
	// i = ft_printf("ft_printf: %s\n", "OK");
	// i -= printf("printf: %s\n", "OK");
	// printf("Diff : %d\n", i);
	// ft_putendl("");
	// check_error(i - 3);

	// ft_putendl("Test 02 - %S:");
	// i = ft_printf("ft_printf: %S\n", L"▄︻̷̿┻̿═━一");
	// i -= printf("printf: %s\n", "OK");
	// printf("Diff : %d\n", i);
	// ft_putendl("");
	// check_error(i - 3);

	ft_putendl("Test 03 - %p:");
	i = ft_printf("ft_printf: %p\n", b);
	i -= printf("printf: %p\n", b);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 04 - %d:");
	i = ft_printf("ft_printf: %d\n", a);
	i -= printf("printf: %d\n", a);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 05 - %D:");
	i = ft_printf("ft_printf: %D\n", a);
	i -= printf("printf: %D\n", a);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 06 - %i:");
	i = ft_printf("ft_printf: %i\n", a);
	i -= printf("printf: %i\n", a);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 07 - %o:");
	i = ft_printf("ft_printf: %o\n", 34);
	i -= printf("printf: %o\n", 34);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 08 - %O:");
	i = ft_printf("ft_printf: %O\n", 34);
	i -= printf("printf: %O\n", 34);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 09 - %u:");
	i = ft_printf("ft_printf: %u\n", (unsigned int)4200000000);
	i -= printf("printf: %u\n", (unsigned int)4200000000);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 10 - %U:");
	i = ft_printf("ft_printf: %U\n", (unsigned int)4200000000);
	i -= printf("printf: %U\n", (unsigned int)4200000000);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 11 - %x:");
	i = ft_printf("ft_printf: %x\n", (unsigned)a);
	i -= printf("printf: %x\n", (unsigned)a);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 12 - %X:");
	i = ft_printf("ft_printf: %X\n", (unsigned)a);
	i -= printf("printf: %X\n", (unsigned)a);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 13 - %c:");
	i = ft_printf("ft_printf: %c\n", 'a');
	i -= printf("printf: %c\n", 'a');
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 14 - %C:");
	i = ft_printf("ft_printf: %C\n", L'腹');
	i -= printf("printf: %C\n", L'腹');
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 15 - %#o:");
	i = ft_printf("ft_printf: %#o\n", 34);
	i -= printf("printf: %#o\n", 34);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 16 - %#x:");
	i = ft_printf("ft_printf: %#x\n", 42);
	i -= printf("printf: %#x\n", 42);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 17 - %#X:");
	i = ft_printf("ft_printf: %#X\n", 42);
	i -= printf("printf: %#X\n", 42);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 18 - %08d:");
	i = ft_printf("ft_printf: %08d\n", 42);
	i -= printf("printf: %08d\n", 42);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 19 - %-8d:");
	i = ft_printf("ft_printf: %-8d\n", 42);
	i -= printf("printf: %-8d\n", 42);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 20 - %+d:");
	i = ft_printf("ft_printf: %+d\n", 42);
	i -= printf("printf: %+d\n", 42);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 21 - % d:");
	i = ft_printf("ft_printf: % d\n", 42);
	i -= printf("printf: % d\n", 42);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 22 - %8d:");
	i = ft_printf("ft_printf: %8d\n", 42);
	i -= printf("printf: %8d\n", 42);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	// ft_putendl("Test 23 - %.2f:");
	// i = ft_printf("ft_printf: %.2f\n", 42.314159265359);
	// i -= printf("printf: %.2f\n", 42.314159265359);
	// printf("Diff : %d\n", i - 3);
	// ft_putendl("");
	// check_error(i - 3);

	ft_putendl("Test 24 - %hhd:");
	i = ft_printf("ft_printf: %hhd\n", (char)'a');
	i -= printf("printf: %hhd\n", (char)'a');
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 25 - %hd:");
	i = ft_printf("ft_printf: %hd\n", (short)4200);
	i -= printf("printf: %hd\n", (short)4200);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 26 - %ld:");
	i = ft_printf("ft_printf: %ld\n", (long)420000000);
	i -= printf("printf: %ld\n", (long)420000000);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 27 - %lld:");
	i = ft_printf("ft_printf: %lld\n", (long long)420000000);
	i -= printf("printf: %lld\n", (long long)420000000);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 28 - %jd:");
	i = ft_printf("ft_printf: %jd\n", (intmax_t)420000000);
	i -= printf("printf: %jd\n", (intmax_t)420000000);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

	ft_putendl("Test 29 - %zd:");
	i = ft_printf("ft_printf: %zd\n", (size_t)42);
	i -= printf("printf: %zd\n", (size_t)42);
	printf("Diff : %d\n", i - 3);
	ft_putendl("");
	check_error(i - 3);

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
