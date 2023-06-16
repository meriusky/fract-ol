/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:43:51 by mehernan          #+#    #+#             */
/*   Updated: 2022/06/15 13:20:03 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	count;
	char	*n;

	count = 0;
	n = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!n)
		return (NULL);
	while (s[count] != '\0')
	{
		n[count] = f(count, s[count]);
		count++;
	}
	n[count] = '\0';
	return (n);
}
