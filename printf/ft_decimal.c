/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:02:18 by mehernan          #+#    #+#             */
/*   Updated: 2022/10/11 18:13:39 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_num(int number, int n)
{
	char	digito;
	char	result[20];

	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	result[number] = '\0';
	number--;
	while (n != 0)
	{
		digito = '0' + (n % 10);
		n = n / 10;
		result[number] = digito;
		number--;
	}
	if (ft_string(result) == -1)
		return (-1);
	return (0);
}

static int	calcular_numero_de_digitos(int n)
{
	int	num_dig;

	num_dig = 0;
	if (n < 0)
		num_dig++;
	while (n != 0)
	{
		n = n / 10;
		num_dig++;
	}
	return (num_dig);
}

int	number_to_character(int n, int *res)
{
	if (n == -2147483648)
	{
		*res = ft_string("-2147483648");
		if (*res == -1)
			return (-1);
	}
	else if (n == 0)
	{
		*res = ft_string("0");
		if (*res == -1)
			return (-1);
	}
	else
	{
		*res = calcular_numero_de_digitos(n);
		if (print_num(*res, n) == -1)
			return (-1);
	}
	return (0);
}

int	ft_decimal(int d)
{
	int		res;

	if (number_to_character(d, &res) == -1)
		return (-1);
	return (res);
}
