/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:46:52 by mehernan          #+#    #+#             */
/*   Updated: 2022/10/09 21:31:18 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	hex_rep_and_printx(unsigned int x, char *new, int i)
{
	int		count;
	char	c;

	while (x > 0)
	{
		c = "0123456789abcdef"[x % 16];
		x /= 16;
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	count = i;
	while (--i >= 0)
	{
		if (ft_character(new[i]) == -1)
			return (-1);
	}
	return (count);
}

int	ft_hexadecimal_min(unsigned int x)
{
	int		i;
	int		count;
	char	new[21];

	i = 0;
	if (!x)
	{
		if (ft_character('0') == -1)
			return (-1);
		return (1);
	}
	count = hex_rep_and_printx(x, new, i);
	return (count);
}
