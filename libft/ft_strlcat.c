/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:24:13 by mehernan          #+#    #+#             */
/*   Updated: 2022/05/22 13:00:40 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	dstlen;

	count = 0;
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + ft_strlen(src));
	while (src[count] != '\0' && dstlen + 1 < dstsize)
	{
		dst[dstlen] = src[count];
		dstlen++;
		count++;
	}
	dst[dstlen] = '\0';
	return (dstlen + ft_strlen(&src[count]));
}
