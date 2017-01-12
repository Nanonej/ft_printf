/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:10:29 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/12 18:29:20 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>
#include <locale.h>

// int		main(void)
// {
// 	// setlocale(LC_ALL, "en_US");
// 	// ft_putnbr(ft_printf("%s", 'a'));
// 	printf("%s\n", ft_itoa_base(6545, 10, 1));
// 	return (0);
// }

// printf("Minus : %c\n", form->minus);
// printf("Plus : %c\n", form->plus);
// printf("Zero : %c\n", form->zero);
// printf("Space : %c\n", form->space);
// printf("hash : %c\n", form->hash);
// printf("len : %d\n", form->len);
// printf("prec : %d\n", form->prec);
// printf("mod : %s\n", form->mod);
// printf("conv : %c\n", form->conv);

int		main(void)
{
	ft_printf("%.5f\n", 0.15);
	// char *ptr;
	//
	// setlocale(LC_ALL, "en_US");
	// printf("\n");
	//
	// printf("Test %%-8c - %-8c\n", 'A');
	// printf("Test %%+8c - %+8c\n", 'A');
	// printf("Test %%08c - %08c\n", 'A');
	// printf("Test %% 8c - % 8c\n", 'A');
	// printf("Test %%#c - %#c\n", 'A');
	// printf("Test %%8c - %8c\n", 'A');
	// printf("Test %%8.2c - %8.2c\n\n", 'A');
	// printf("Test %%+ 8c - %+ 8c\n", 'A');
	// printf("Test %%- 8c - %- 8c\n", 'A');
	// printf("Test %%+-8c - %+-8c\n", 'A');
	// printf("Test %%-+ 8c - %-+ 8c\n", 'A');
	// printf("Test %%+08c - %+08c\n", 'A');
	// printf("Test %%-08c - %-08c\n", 'A');
	// printf("Test %%0 8c - %0 8c\n", 'A');
	// printf("Test %%+-08c - %+-08c\n", 'A');
	// printf("Test %%+- 08c - %+- 08c\n", 'A');
	// printf("Test %%+ 08c - %+ 08c\n", 'A');
	// printf("Test %%- 8c - %- 08c\n", 'A');
	// printf("Test %%+ 8.2c - %+ 8.2c\n", 'A');
	// printf("Test %%- 8.2c - %- 8.2c\n", 'A');
	// printf("Test %%+-8.2c - %+-8.2c\n", 'A');
	// printf("Test %%-+ 8.2c - %-+ 8.2c\n", 'A');
	// printf("Test %%+08.2c - %+08.2c\n", 'A');
	// printf("Test %%-08.2c - %-08.2c\n", 'A');
	// printf("Test %%0 8.2c - %0 8.2c\n", 'A');
	// printf("Test %%+-08.2c - %+-08.2c\n", 'A');
	// printf("Test %%+- 08.2c - %+- 08.2c\n", 'A');
	// printf("Test %%+ 08.2c - %+ 08.2c\n", 'A');
	// printf("Test %%- 8.2c - %- 08.2c\n\n", 'A');
	//
	// printf("Test %%-8C - %-8C\n", L'A');
	// printf("Test %%+8C - %+8C\n", L'A');
	// printf("Test %%08C - %08C\n", L'A');
	// printf("Test %% 8C - % 8C\n", L'A');
	// printf("Test %%#C - %#C\n", L'A');
	// printf("Test %%8C - %8C\n", L'A');
	// printf("Test %%8.2C - %8.2C\n\n", L'A');
	// printf("Test %%+ 8C - %+ 8C\n", L'A');
	// printf("Test %%- 8C - %- 8C\n", L'A');
	// printf("Test %%+-8C - %+-8C\n", L'A');
	// printf("Test %%-+ 8C - %-+ 8C\n", L'A');
	// printf("Test %%+08C - %+08C\n", L'A');
	// printf("Test %%-08C - %-08C\n", L'A');
	// printf("Test %%0 8C - %0 8C\n", L'A');
	// printf("Test %%+-08C - %+-08C\n", L'A');
	// printf("Test %%+- 08C - %+- 08C\n", L'A');
	// printf("Test %%+ 08C - %+ 08C\n", L'A');
	// printf("Test %%- 8C - %- 08C\n", L'A');
	// printf("Test %%+ 8.2C - %+ 8.2C\n", L'A');
	// printf("Test %%- 8.2C - %- 8.2C\n", L'A');
	// printf("Test %%+-8.2C - %+-8.2C\n", L'A');
	// printf("Test %%-+ 8.2C - %-+ 8.2C\n", L'A');
	// printf("Test %%+08.2C - %+08.2C\n", L'A');
	// printf("Test %%-08.2C - %-08.2C\n", L'A');
	// printf("Test %%0 8.2C - %0 8.2C\n", L'A');
	// printf("Test %%+-08.2C - %+-08.2C\n", L'A');
	// printf("Test %%+- 08.2C - %+- 08.2C\n", L'A');
	// printf("Test %%+ 08.2C - %+ 08.2C\n", L'A');
	// printf("Test %%- 8.2C - %- 08.2C\n\n", L'A');
	//
	// printf("Test %%-8s - %-8s\n", "POUET");
	// printf("Test %%+8s - %+8s\n", "POUET");
	// printf("Test %%08s - %08s\n", "POUET");
	// printf("Test %% 8s - % 8s\n", "POUET");
	// printf("Test %%#s - %#s\n", "POUET");
	// printf("Test %%8s - %8s\n", "POUET");
	// printf("Test %%8.2s - %8.2s\n\n", "POUET");
	// printf("Test %%+ 8s - %+ 8s\n", "POUET");
	// printf("Test %%- 8s - %- 8s\n", "POUET");
	// printf("Test %%+-8s - %+-8s\n", "POUET");
	// printf("Test %%-+ 8s - %-+ 8s\n", "POUET");
	// printf("Test %%+08s - %+08s\n", "POUET");
	// printf("Test %%-08s - %-08s\n", "POUET");
	// printf("Test %%0 8s - %0 8s\n", "POUET");
	// printf("Test %%+-08s - %+-08s\n", "POUET");
	// printf("Test %%+- 08s - %+- 08s\n", "POUET");
	// printf("Test %%+ 08s - %+ 08s\n", "POUET");
	// printf("Test %%- 8s - %- 08s\n", "POUET");
	// printf("Test %%+ 8.2s - %+ 8.2s\n", "POUET");
	// printf("Test %%- 8.2s - %- 8.2s\n", "POUET");
	// printf("Test %%+-8.2s - %+-8.2s\n", "POUET");
	// printf("Test %%-+ 8.2s - %-+ 8.2s\n", "POUET");
	// printf("Test %%+08.2s - %+08.2s\n", "POUET");
	// printf("Test %%-08.2s - %-08.2s\n", "POUET");
	// printf("Test %%0 8.2s - %0 8.2s\n", "POUET");
	// printf("Test %%+-08.2s - %+-08.2s\n", "POUET");
	// printf("Test %%+- 08.2s - %+- 08.2s\n", "POUET");
	// printf("Test %%+ 08.2s - %+ 08.2s\n", "POUET");
	// printf("Test %%- 8.2s - %- 08.2s\n\n", "POUET");
	//
	// printf("Test %%-8S - %-8S\n", L"POUET");
	// printf("Test %%+8S - %+8S\n", L"POUET");
	// printf("Test %%08S - %08S\n", L"POUET");
	// printf("Test %% 8S - % 8S\n", L"POUET");
	// printf("Test %%#S - %#S\n", L"POUET");
	// printf("Test %%8S - %8S\n", L"POUET");
	// printf("Test %%8.2S - %8.2S\n\n", L"POUET");
	// printf("Test %%+ 8S - %+ 8S\n", L"POUET");
	// printf("Test %%- 8S - %- 8S\n", L"POUET");
	// printf("Test %%+-8S - %+-8S\n", L"POUET");
	// printf("Test %%-+ 8S - %-+ 8S\n", L"POUET");
	// printf("Test %%+08S - %+08S\n", L"POUET");
	// printf("Test %%-08S - %-08S\n", L"POUET");
	// printf("Test %%0 8S - %0 8S\n", L"POUET");
	// printf("Test %%+-08S - %+-08S\n", L"POUET");
	// printf("Test %%+- 08S - %+- 08S\n", L"POUET");
	// printf("Test %%+ 08S - %+ 08S\n", L"POUET");
	// printf("Test %%- 8S - %- 08S\n", L"POUET");
	// printf("Test %%+ 8.2S - %+ 8.2S\n", L"POUET");
	// printf("Test %%- 8.2S - %- 8.2S\n", L"POUET");
	// printf("Test %%+-8.2S - %+-8.2S\n", L"POUET");
	// printf("Test %%-+ 8.2S - %-+ 8.2S\n", L"POUET");
	// printf("Test %%+08.2S - %+08.2S\n", L"POUET");
	// printf("Test %%-08.2S - %-08.2S\n", L"POUET");
	// printf("Test %%0 8.2S - %0 8.2S\n", L"POUET");
	// printf("Test %%+-08.2S - %+-08.2S\n", L"POUET");
	// printf("Test %%+- 08.2S - %+- 08.2S\n", L"POUET");
	// printf("Test %%+ 08.2S - %+ 08.2S\n", L"POUET");
	// printf("Test %%- 8.2S - %- 08.2S\n\n", L"POUET");
	//
	// printf("Test %%-8p - %-8p\n", ptr);
	// printf("Test %%+8p - %+8p\n", ptr);
	// printf("Test %%08p - %08p\n", ptr);
	// printf("Test %% 8p - % 8p\n", ptr);
	// printf("Test %%#p - %#p\n", ptr);
	// printf("Test %%8p - %8p\n", ptr);
	// printf("Test %%8.2p - %8.2p\n\n", ptr);
	// printf("Test %%+ 8p - %+ 8p\n", ptr);
	// printf("Test %%- 8p - %- 8p\n", ptr);
	// printf("Test %%+-8p - %+-8p\n", ptr);
	// printf("Test %%-+ 8p - %-+ 8p\n", ptr);
	// printf("Test %%+08p - %+08p\n", ptr);
	// printf("Test %%-08p - %-08p\n", ptr);
	// printf("Test %%0 8p - %0 8p\n", ptr);
	// printf("Test %%+-08p - %+-08p\n", ptr);
	// printf("Test %%+- 08p - %+- 08p\n", ptr);
	// printf("Test %%+ 08p - %+ 08p\n", ptr);
	// printf("Test %%- 8p - %- 08p\n", ptr);
	// printf("Test %%+ 8.2p - %+ 8.2p\n", ptr);
	// printf("Test %%- 8.2p - %- 8.2p\n", ptr);
	// printf("Test %%+-8.2p - %+-8.2p\n", ptr);
	// printf("Test %%-+ 8.2p - %-+ 8.2p\n", ptr);
	// printf("Test %%+08.2p - %+08.2p\n", ptr);
	// printf("Test %%-08.2p - %-08.2p\n", ptr);
	// printf("Test %%0 8.2p - %0 8.2p\n", ptr);
	// printf("Test %%+-08.2p - %+-08.2p\n", ptr);
	// printf("Test %%+- 08.2p - %+- 08.2p\n", ptr);
	// printf("Test %%+ 08.2p - %+ 08.2p\n", ptr);
	// printf("Test %%- 8.2p - %- 08.2p\n\n", ptr);
	//
	// printf("Test %%%%-8 - %%-8\n");
	// printf("Test %%%%+8 - %%+8\n");
	// printf("Test %%%%08 - %%08\n");
	// printf("Test %%%% 8 - %% 8\n");
	// printf("Test %%%%# - %%#\n");
	// printf("Test %%%%8 - %%8\n");
	// printf("Test %%%%8.2 - %%8.2\n\n");
	// printf("Test %%%%+ 8 - %%+ 8\n");
	// printf("Test %%%%- 8 - %%- 8\n");
	// printf("Test %%%%+-8 - %%+-8\n");
	// printf("Test %%%%-+ 8 - %%-+ 8\n");
	// printf("Test %%%%+08 - %%+08\n");
	// printf("Test %%%%-08 - %%-08\n");
	// printf("Test %%%%0 8 - %%0 8\n");
	// printf("Test %%%%+-08 - %%+-08\n");
	// printf("Test %%%%+- 08 - %%+- 08\n");
	// printf("Test %%%%+ 08 - %%+ 08\n");
	// printf("Test %%%%- 8 - %%- 08\n");
	// printf("Test %%%%+ 8.2 - %%+ 8.2\n");
	// printf("Test %%%%- 8.2 - %%- 8.2\n");
	// printf("Test %%%%+-8.2 - %%+-8.2\n");
	// printf("Test %%%%-+ 8.2 - %%-+ 8.2\n");
	// printf("Test %%%%+08.2 - %%+08.2\n");
	// printf("Test %%%%-08.2 - %%-08.2\n");
	// printf("Test %%%%0 8.2 - %%0 8.2\n");
	// printf("Test %%%%+-08.2 - %%+-08.2\n");
	// printf("Test %%%%+- 08.2 - %%+- 08.2\n");
	// printf("Test %%%%+ 08.2 - %%+ 08.2\n");
	// printf("Test %%%%- 8.2 - %%- 08.2\n\n");
	//
	// printf("Test %%-8d - %-8d\n", 42450);
	// printf("Test %%+8d - %+8d\n", 42450);
	// printf("Test %%08d - %08d\n", 42450);
	// printf("Test %% 8d - % 8d\n", 42450);
	// printf("Test %%#d - %#d\n", 42450);
	// printf("Test %%8d - %8d\n", 42450);
	// printf("Test %%8.2d - %8.2d\n\n", 42450);
	// printf("Test %%+ 8d - %+ 8d\n", 42450);
	// printf("Test %%- 8d - %- 8d\n", 42450);
	// printf("Test %%+-8d - %+-8d\n", 42450);
	// printf("Test %%-+ 8d - %-+ 8d\n", 42450);
	// printf("Test %%+08d - %+08d\n", 42450);
	// printf("Test %%-08d - %-08d\n", 42450);
	// printf("Test %%0 8d - %0 8d\n", 42450);
	// printf("Test %%+-08d - %+-08d\n", 42450);
	// printf("Test %%+- 08d - %+- 08d\n", 42450);
	// printf("Test %%+ 08d - %+ 08d\n", 42450);
	// printf("Test %%- 8d - %- 08d\n", 42450);
	// printf("Test %%+ 8.2d - %+ 8.2d\n", 42450);
	// printf("Test %%- 8.2d - %- 8.2d\n", 42450);
	// printf("Test %%+-8.2d - %+-8.2d\n", 42450);
	// printf("Test %%-+ 8.2d - %-+ 8.2d\n", 42450);
	// printf("Test %%+08.2d - %+08.2d\n", 42450);
	// printf("Test %%-08.2d - %-08.2d\n", 42450);
	// printf("Test %%0 8.2d - %0 8.2d\n", 42450);
	// printf("Test %%+-08.2d - %+-08.2d\n", 42450);
	// printf("Test %%+- 08.2d - %+- 08.2d\n", 42450);
	// printf("Test %%+ 08.2d - %+ 08.2d\n", 42450);
	// printf("Test %%- 8.2d - %- 08.2d\n\n", 42450);
	//
	// printf("Test %%-8i - %-8i\n", 42);
	// printf("Test %%+8i - %+8i\n", 42);
	// printf("Test %%08i - %08i\n", 42);
	// printf("Test %% 8i - % 8i\n", 42);
	// printf("Test %%#i - %#i\n", 42);
	// printf("Test %%8i - %8i\n", 42);
	// printf("Test %%8.2i - %8.2i\n\n", 42);
	// printf("Test %%+ 8i - %+ 8i\n", 42);
	// printf("Test %%- 8i - %- 8i\n", 42);
	// printf("Test %%+-8i - %+-8i\n", 42);
	// printf("Test %%-+ 8i - %-+ 8i\n", 42);
	// printf("Test %%+08i - %+08i\n", 42);
	// printf("Test %%-08i - %-08i\n", 42);
	// printf("Test %%0 8i - %0 8i\n", 42);
	// printf("Test %%+-08i - %+-08i\n", 42);
	// printf("Test %%+- 08i - %+- 08i\n", 42);
	// printf("Test %%+ 08i - %+ 08i\n", 42);
	// printf("Test %%- 8i - %- 08i\n", 42);
	// printf("Test %%+ 8.2i - %+ 8.2i\n", 42);
	// printf("Test %%- 8.2i - %- 8.2i\n", 42);
	// printf("Test %%+-8.2i - %+-8.2i\n", 42);
	// printf("Test %%-+ 8.2i - %-+ 8.2i\n", 42);
	// printf("Test %%+08.2i - %+08.2i\n", 42);
	// printf("Test %%-08.2i - %-08.2i\n", 42);
	// printf("Test %%0 8.2i - %0 8.2i\n", 42);
	// printf("Test %%+-08.2i - %+-08.2i\n", 42);
	// printf("Test %%+- 08.2i - %+- 08.2i\n", 42);
	// printf("Test %%+ 08.2i - %+ 08.2i\n", 42);
	// printf("Test %%- 8.2i - %- 08.2i\n\n", 42);
	//
	// printf("Test %%-8o - %-8o\n", 34);
	// printf("Test %%+8o - %+8o\n", 34);
	// printf("Test %%08o - %08o\n", 34);
	// printf("Test %% 8o - % 8o\n", 34);
	// printf("Test %%#o - %#o\n", 34);
	// printf("Test %%8o - %8o\n", 34);
	// printf("Test %%8.2o - %8.2o\n\n", 34);
	// printf("Test %%+ 8o - %+ 8o\n", 34);
	// printf("Test %%- 8o - %- 8o\n", 34);
	// printf("Test %%+-8o - %+-8o\n", 34);
	// printf("Test %%-+ 8o - %-+ 8o\n", 34);
	// printf("Test %%+08o - %+08o\n", 34);
	// printf("Test %%-08o - %-08o\n", 34);
	// printf("Test %%0 8o - %0 8o\n", 34);
	// printf("Test %%+-08o - %+-08o\n", 34);
	// printf("Test %%+- 08o - %+- 08o\n", 34);
	// printf("Test %%+ 08o - %+ 08o\n", 34);
	// printf("Test %%- 8o - %- 08o\n", 34);
	// printf("Test %%+ 8.2o - %+ 8.2o\n", 34);
	// printf("Test %%- 8.2o - %- 8.2o\n", 34);
	// printf("Test %%+-8.2o - %+-8.2o\n", 34);
	// printf("Test %%-+ 8.2o - %-+ 8.2o\n", 34);
	// printf("Test %%+08.2o - %+08.2o\n", 34);
	// printf("Test %%-08.2o - %-08.2o\n", 34);
	// printf("Test %%0 8.2o - %0 8.2o\n", 34);
	// printf("Test %%+-08.2o - %+-08.2o\n", 34);
	// printf("Test %%+- 08.2o - %+- 08.2o\n", 34);
	// printf("Test %%+ 08.2o - %+ 08.2o\n", 34);
	// printf("Test %%- 8.2o - %- 08.2o\n\n", 34);
	//
	// printf("Test %%-8O - %-8O\n", 34);
	// printf("Test %%+8O - %+8O\n", 34);
	// printf("Test %%08O - %08O\n", 34);
	// printf("Test %% 8O - % 8O\n", 34);
	// printf("Test %%#O - %#O\n", 34);
	// printf("Test %%8O - %8O\n", 34);
	// printf("Test %%8.2O - %8.2O\n\n", 34);
	// printf("Test %%+ 8O - %+ 8O\n", 34);
	// printf("Test %%- 8O - %- 8O\n", 34);
	// printf("Test %%+-8O - %+-8O\n", 34);
	// printf("Test %%-+ 8O - %-+ 8O\n", 34);
	// printf("Test %%+08O - %+08O\n", 34);
	// printf("Test %%-08O - %-08O\n", 34);
	// printf("Test %%0 8O - %0 8O\n", 34);
	// printf("Test %%+-08O - %+-08O\n", 34);
	// printf("Test %%+- 08O - %+- 08O\n", 34);
	// printf("Test %%+ 08O - %+ 08O\n", 34);
	// printf("Test %%- 8O - %- 08O\n", 34);
	// printf("Test %%+ 8.2O - %+ 8.2O\n", 34);
	// printf("Test %%- 8.2O - %- 8.2O\n", 34);
	// printf("Test %%+-8.2O - %+-8.2O\n", 34);
	// printf("Test %%-+ 8.2O - %-+ 8.2O\n", 34);
	// printf("Test %%+08.2O - %+08.2O\n", 34);
	// printf("Test %%-08.2O - %-08.2O\n", 34);
	// printf("Test %%0 8.2O - %0 8.2O\n", 34);
	// printf("Test %%+-08.2O - %+-08.2O\n", 34);
	// printf("Test %%+- 08.2O - %+- 08.2O\n", 34);
	// printf("Test %%+ 08.2O - %+ 08.2O\n", 34);
	// printf("Test %%- 8.2O - %- 08.2O\n\n", 34);
	//
	// printf("Test %%-8u - %-8u\n", (unsigned int)4200000000);
	// printf("Test %%+8u - %+8u\n", (unsigned int)4200000000);
	// printf("Test %%08u - %08u\n", (unsigned int)4200000000);
	// printf("Test %% 8u - % 8u\n", (unsigned int)4200000000);
	// printf("Test %%#u - %#u\n", (unsigned int)4200000000);
	// printf("Test %%8u - %8u\n", (unsigned int)4200000000);
	// printf("Test %%8.2u - %8.2u\n\n", (unsigned int)4200000000);
	// printf("Test %%+ 8u - %+ 8u\n", (unsigned int)4200000000);
	// printf("Test %%- 8u - %- 8u\n", (unsigned int)4200000000);
	// printf("Test %%+-8u - %+-8u\n", (unsigned int)4200000000);
	// printf("Test %%-+ 8u - %-+ 8u\n", (unsigned int)4200000000);
	// printf("Test %%+08u - %+08u\n", (unsigned int)4200000000);
	// printf("Test %%-08u - %-08u\n", (unsigned int)4200000000);
	// printf("Test %%0 8u - %0 8u\n", (unsigned int)4200000000);
	// printf("Test %%+-08u - %+-08u\n", (unsigned int)4200000000);
	// printf("Test %%+- 08u - %+- 08u\n", (unsigned int)4200000000);
	// printf("Test %%+ 08u - %+ 08u\n", (unsigned int)4200000000);
	// printf("Test %%- 8u - %- 08u\n", (unsigned int)4200000000);
	// printf("Test %%+ 8.2u - %+ 8.2u\n", (unsigned int)4200000000);
	// printf("Test %%- 8.2u - %- 8.2u\n", (unsigned int)4200000000);
	// printf("Test %%+-8.2u - %+-8.2u\n", (unsigned int)4200000000);
	// printf("Test %%-+ 8.2u - %-+ 8.2u\n", (unsigned int)4200000000);
	// printf("Test %%+08.2u - %+08.2u\n", (unsigned int)4200000000);
	// printf("Test %%-08.2u - %-08.2u\n", (unsigned int)4200000000);
	// printf("Test %%0 8.2u - %0 8.2u\n", (unsigned int)4200000000);
	// printf("Test %%+-08.2u - %+-08.2u\n", (unsigned int)4200000000);
	// printf("Test %%+- 08.2u - %+- 08.2u\n", (unsigned int)4200000000);
	// printf("Test %%+ 08.2u - %+ 08.2u\n", (unsigned int)4200000000);
	// printf("Test %%- 8.2u - %- 08.2u\n\n", (unsigned int)4200000000);
	//
	// printf("Test %%-8U - %-8U\n", (unsigned int)4200000000);
	// printf("Test %%+8U - %+8U\n", (unsigned int)4200000000);
	// printf("Test %%08U - %08U\n", (unsigned int)4200000000);
	// printf("Test %% 8U - % 8U\n", (unsigned int)4200000000);
	// printf("Test %%#U - %#U\n", (unsigned int)4200000000);
	// printf("Test %%8U - %8U\n", (unsigned int)4200000000);
	// printf("Test %%8.2U - %8.2U\n\n", (unsigned int)4200000000);
	// printf("Test %%+ 8U - %+ 8U\n", (unsigned int)4200000000);
	// printf("Test %%- 8U - %- 8U\n", (unsigned int)4200000000);
	// printf("Test %%+-8U - %+-8U\n", (unsigned int)4200000000);
	// printf("Test %%-+ 8U - %-+ 8U\n", (unsigned int)4200000000);
	// printf("Test %%+08U - %+08U\n", (unsigned int)4200000000);
	// printf("Test %%-08U - %-08U\n", (unsigned int)4200000000);
	// printf("Test %%0 8U - %0 8U\n", (unsigned int)4200000000);
	// printf("Test %%+-08U - %+-08U\n", (unsigned int)4200000000);
	// printf("Test %%+- 08U - %+- 08U\n", (unsigned int)4200000000);
	// printf("Test %%+ 08U - %+ 08U\n", (unsigned int)4200000000);
	// printf("Test %%- 8U - %- 08U\n", (unsigned int)4200000000);
	// printf("Test %%+ 8.2U - %+ 8.2U\n", (unsigned int)4200000000);
	// printf("Test %%- 8.2U - %- 8.2U\n", (unsigned int)4200000000);
	// printf("Test %%+-8.2U - %+-8.2U\n", (unsigned int)4200000000);
	// printf("Test %%-+ 8.2U - %-+ 8.2U\n", (unsigned int)4200000000);
	// printf("Test %%+08.2U - %+08.2U\n", (unsigned int)4200000000);
	// printf("Test %%-08.2U - %-08.2U\n", (unsigned int)4200000000);
	// printf("Test %%0 8.2U - %0 8.2U\n", (unsigned int)4200000000);
	// printf("Test %%+-08.2U - %+-08.2U\n", (unsigned int)4200000000);
	// printf("Test %%+- 08.2U - %+- 08.2U\n", (unsigned int)4200000000);
	// printf("Test %%+ 08.2U - %+ 08.2U\n", (unsigned int)4200000000);
	// printf("Test %%- 8.2U - %- 08.2U\n\n", (unsigned int)4200000000);
	//
	// printf("Test %%-8x - %-8x\n", 42);
	// printf("Test %%+8x - %+8x\n", 42);
	// printf("Test %%08x - %08x\n", 42);
	// printf("Test %% 8x - % 8x\n", 42);
	// printf("Test %%#x - %#x\n", 42);
	// printf("Test %%8x - %8x\n", 42);
	// printf("Test %%8.2x - %8.2x\n\n", 42);
	// printf("Test %%+ 8x - %+ 8x\n", 42);
	// printf("Test %%- 8x - %- 8x\n", 42);
	// printf("Test %%+-8x - %+-8x\n", 42);
	// printf("Test %%-+ 8x - %-+ 8x\n", 42);
	// printf("Test %%+08x - %+08x\n", 42);
	// printf("Test %%-08x - %-08x\n", 42);
	// printf("Test %%0 8x - %0 8x\n", 42);
	// printf("Test %%+-08x - %+-08x\n", 42);
	// printf("Test %%+- 08x - %+- 08x\n", 42);
	// printf("Test %%+ 08x - %+ 08x\n", 42);
	// printf("Test %%- 8x - %- 08x\n", 42);
	// printf("Test %%+ 8.2x - %+ 8.2x\n", 42);
	// printf("Test %%- 8.2x - %- 8.2x\n", 42);
	// printf("Test %%+-8.2x - %+-8.2x\n", 42);
	// printf("Test %%-+ 8.2x - %-+ 8.2x\n", 42);
	// printf("Test %%+08.2x - %+08.2x\n", 42);
	// printf("Test %%-08.2x - %-08.2x\n", 42);
	// printf("Test %%0 8.2x - %0 8.2x\n", 42);
	// printf("Test %%+-08.2x - %+-08.2x\n", 42);
	// printf("Test %%+- 08.2x - %+- 08.2x\n", 42);
	// printf("Test %%+ 08.2x - %+ 08.2x\n", 42);
	// printf("Test %%- 8.2x - %- 08.2x\n\n", 42);
	//
	// printf("Test %%-8X - %-8X\n", 42);
	// printf("Test %%+8X - %+8X\n", 42);
	// printf("Test %%08X - %08X\n", 42);
	// printf("Test %% 8X - % 8X\n", 42);
	// printf("Test %%#X - %#X\n", 42);
	// printf("Test %%8X - %8X\n", 42);
	// printf("Test %%8.2X - %8.2X\n\n", 42);
	// printf("Test %%+ 8X - %+ 8X\n", 42);
	// printf("Test %%- 8X - %- 8X\n", 42);
	// printf("Test %%+-8X - %+-8X\n", 42);
	// printf("Test %%-+ 8X - %-+ 8X\n", 42);
	// printf("Test %%+08X - %+08X\n", 42);
	// printf("Test %%-08X - %-08X\n", 42);
	// printf("Test %%0 8X - %0 8X\n", 42);
	// printf("Test %%+-08X - %+-08X\n", 42);
	// printf("Test %%+- 08X - %+- 08X\n", 42);
	// printf("Test %%+ 08X - %+ 08X\n", 42);
	// printf("Test %%- 8X - %- 08X\n", 42);
	// printf("Test %%+ 8.2X - %+ 8.2X\n", 42);
	// printf("Test %%- 8.2X - %- 8.2X\n", 42);
	// printf("Test %%+-8.2X - %+-8.2X\n", 42);
	// printf("Test %%-+ 8.2X - %-+ 8.2X\n", 42);
	// printf("Test %%+08.2X - %+08.2X\n", 42);
	// printf("Test %%-08.2X - %-08.2X\n", 42);
	// printf("Test %%0 8.2X - %0 8.2X\n", 42);
	// printf("Test %%+-08.2X - %+-08.2X\n", 42);
	// printf("Test %%+- 08.2X - %+- 08.2X\n", 42);
	// printf("Test %%+ 08.2X - %+ 08.2X\n", 42);
	// printf("Test %%- 8.2X - %- 08.2X\n\n", 42);
	return (0);
}
