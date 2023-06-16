/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:52:32 by mehernan          #+#    #+#             */
/*   Updated: 2022/05/19 13:21:51 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*ptra;
	char	*ptrb;

	if (!dst && !src)
		return (NULL);
	count = 0;
	ptra = (char *)dst;
	ptrb = (char *)src;
	while (count < n)
	{
		ptra[count] = ptrb[count];
		count++;
	}
	return (dst);
}
