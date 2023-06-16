/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:22:38 by mehernan          #+#    #+#             */
/*   Updated: 2022/05/22 20:46:38 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != '\0' && (s[count] != (unsigned char)c))
		count++;
	if ((unsigned char)c == s[count])
		return ((char *)&s[count]);
	else if (c == '\0')
		return ((char *)&s[count]);
	return (NULL);
}	
