/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:13:33 by mehernan          #+#    #+#             */
/*   Updated: 2022/05/25 23:58:41 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while (cont < n)
	{
		if (*(unsigned char *)(s1 + cont) != *(unsigned char *)(s2 + cont))
			return (*(unsigned char *)(s1 + cont) - \
					*(unsigned char *)(s2 + cont));
		else
			cont++;
	}
	return (0);
}
