/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:41:43 by mehernan          #+#    #+#             */
/*   Updated: 2022/10/11 18:10:28 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	hex_rep_and_printp(unsigned long long p, char *new, int i)
{
	int		count;
	char	c;

	while (p > 0)
	{
		c = "0123456789abcdef"[p % 16];
		p /= 16;
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	count = i + 2;
	while (--i >= 0)
	{
		if (ft_character(new[i]) == -1)
			return (-1);
	}
	return (count);
}

int	ft_pointer(unsigned long long p)
{
	int		i;
	int		count;
	char	new[21];

	i = 0;
	if (write(1, "0x", 2) != 2)
		return (-1);
	if (p == 0)
	{
		if (write(1, "0", 1) != 1)
			return (-1);
		return (3);
	}
	count = hex_rep_and_printp(p, new, i);
	return (count);
}
