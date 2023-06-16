/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:27:34 by mehernan          #+#    #+#             */
/*   Updated: 2022/05/24 15:18:19 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	count = ft_strlen(s);
	if ((char)c == '\0' && s[count] == '\0')
	{
		return ((char *)&s[count]);
	}
	while (count > 0)
	{
		count--;
		if (s[count] == (unsigned char)c)
			return ((char *)&s[count]);
	}
	return (NULL);
}
