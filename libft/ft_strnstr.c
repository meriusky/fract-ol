/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:24:26 by mehernan          #+#    #+#             */
/*   Updated: 2022/05/25 23:58:59 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_n_cmpl(const char *haystack, const char *needle, size_t len, int count)
{
	size_t	count2;

	count2 = 0;
	while (needle[count2] != '\0' && len != 0)
	{
		if (haystack[count] != needle[count2])
		{
			return (0);
		}
		count2++;
		count++;
		len--;
	}
	if (count2 == ft_strlen(needle))
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;

	count = 0;
	if (needle[count] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[count] != '\0' && len != 0)
	{
		if (haystack[count] == needle[0])
		{
			if (test_n_cmpl(haystack, needle, len, count) == 1)
			{
				return ((char *)&haystack[count]);
			}
		}
		len--;
		count++;
	}
	return (NULL);
}
