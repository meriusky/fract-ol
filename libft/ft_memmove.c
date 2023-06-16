/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:27:27 by mehernan          #+#    #+#             */
/*   Updated: 2022/05/19 17:33:59 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	count;
	char	*ptrd;
	char	*ptrs;

	count = 0;
	ptrd = (char *)dst;
	ptrs = (char *)src;
	if (ptrd < ptrs)
	{
		while (count < len)
		{
			ptrd[count] = ptrs[count];
			count++;
		}
	}
	else if (ptrd > ptrs)
	{
		count = len;
		while (count > 0)
		{
			count--;
			ptrd[count] = ptrs[count];
		}
	}
	return (dst);
}
