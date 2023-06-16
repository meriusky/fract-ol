/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:25:40 by mehernan          #+#    #+#             */
/*   Updated: 2022/12/03 20:51:15 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	count2;
	char	*result;

	count = 0;
	count2 = 0;
	while (s[count] != '\0')
		count++;
	if (start >= count)
		start = count;
	if (len > count - start)
		result = malloc(sizeof(char) * (count - start + 1));
	else
		result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (start <= count && s[start] != '\0' && count2 < len)
	{
		result[count2] = s[start];
		start++;
		count2++;
	}
	result[count2] = '\0';
	return (result);
}
