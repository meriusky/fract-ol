/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:24:30 by mehernan          #+#    #+#             */
/*   Updated: 2022/05/18 16:52:41 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 	Recibo un puntero a un espacio de la memeoria (void *b
	Relleno con valor 0, n espacios a partir de donde empieza el puntero)
 */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*dst;

	dst = (char *)s;
	count = 0;
	while (count < n)
	{
		dst[count] = 0;
		count++;
	}
}
