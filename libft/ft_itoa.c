/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:56:38 by mehernan          #+#    #+#             */
/*   Updated: 2022/06/22 11:07:01 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lumaca(int number, int n)
{
	char	digito;
	char	*result;

	result = ft_calloc(sizeof(char), (number + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	number--;
	while (n != 0)
	{
		digito = '0' + (n % 10);
		n = n / 10;
		result[number] = digito;
		number--;
	}
	return (result);
}

int	calcular_numero_de_digitos(int n)
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

char	*ft_itoa(int n)
{
	int		numero_de_digitos;
	char	*result;

	if (n == -2147483648)
		result = ft_strdup("-2147483648");
	else if (n == 0)
		result = ft_strdup("0");
	else
	{
		numero_de_digitos = calcular_numero_de_digitos(n);
		result = ft_lumaca(numero_de_digitos, n);
	}
	return (result);
}
