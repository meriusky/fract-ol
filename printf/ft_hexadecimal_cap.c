/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_cap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:00:57 by mehernan          #+#    #+#             */
/*   Updated: 2022/10/20 13:40:02 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	hex_rep_and_printxx(unsigned int bigx, char *new, int i)
{
	int		count;
	char	c;

	while (bigx > 0)
	{
		c = "0123456789ABCDEF"[bigx % 16];
		bigx /= 16;
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

int	ft_hexadecimal_cap(unsigned int bigx)
{
	int		count;
	int		i;
	char	new[21];

	i = 0;
	if (!bigx)
	{
		if (ft_character('0') == -1)
			return (-1);
		return (1);
	}
	count = hex_rep_and_printxx(bigx, new, i);
	return (count);
}
