/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_no_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:22:07 by mehernan          #+#    #+#             */
/*   Updated: 2022/10/10 16:39:33 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_num(int number, unsigned int n)
{
	char	digito;
	char	result[20];

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

static int	calcular_numero_de_digitos(unsigned int n)
{
	int	num_dig;

	num_dig = 0;
	while (n != 0)
	{
		n = n / 10;
		num_dig++;
	}
	return (num_dig);
}

int	number_to_character_no_sign(unsigned int n, int *res)
{
	if (n == 0)
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

int	ft_num_no_sign(unsigned int u)
{
	int		res;

	if (number_to_character_no_sign(u, &res) == -1)
		return (-1);
	return (res);
}
