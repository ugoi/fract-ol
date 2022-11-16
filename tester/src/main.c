/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:49:45 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/16 23:49:29 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int	ft_random(int min, int max)
{
	return (min + rand() / (RAND_MAX / (max - min + 1) + 1));
}

void	fill_complex_number_with_random_values(t_complex *c)
{
	c->real = ft_random(-10, 10);
	c->imaginary = ft_random(-10, 10);
}

void	test_complex(t_complex *(*f)(t_complex*, t_complex*), char operator)
{
	t_complex		c1;
	t_complex		c2;
	double complex	result;
	int				iter;

	iter = 6;
	while (iter--)
	{
		fill_complex_number_with_random_values(&c1);
		fill_complex_number_with_random_values(&c2);
		// printf("c1:	%.2f %+.2f\nc2:	%.2f %+.2f\n", c1.real, c1.imaginary, c2.real, c2.imaginary);
		if (operator == '+')
			result = (c1.real + c1.imaginary * I) + (c2.real + c2.imaginary * I);
		if (operator == '-')
			result = (c1.real + c1.imaginary * I) - (c2.real + c2.imaginary * I);
		if (operator == '*')
			result = (c1.real + c1.imaginary * I) * (c2.real + c2.imaginary * I);
		if (operator == '/')
			result = (c1.real + c1.imaginary * I) / (c2.real + c2.imaginary * I);
		printf("Expected result:	%.2f %+.2fi\n", creal(result), cimag(result));
		(*f)(&c1, &c2);
		printf("Result:			%.2f %+.2fi\n\n", c1.real, c1.imaginary);
	}
}

void	test_add_complex(void)
{
	printf("%s\n\n	TEST_ADD_COMPLEX:	\n", KYEL);
	printf("%s",KNRM);
	test_complex(ft_add_complex, '+');
}

void	test_subtract_complex(void)
{
	printf("%s	TEST_SUBTRACT_COMPLEX:	\n", KYEL);
	printf("%s",KNRM);
	test_complex(ft_subtract_complex, '-');
}

void	test_multiply_complex(void)
{
	printf("%s	TEST_MULTIPLY_COMPLEX:	\n", KYEL);
	printf("%s",KNRM);
	test_complex(ft_multiply_complex, '*');
}

void	test_divide_complex(void)
{
	printf("%s	TEST_DIVIDE_COMPLEX:	\n", KYEL);
	printf("%s",KNRM);
	test_complex(ft_divide_complex, '/');
}

int	main(void)
{
	test_add_complex();
	test_subtract_complex();
	test_multiply_complex();
	test_divide_complex();
	return (0);
}
