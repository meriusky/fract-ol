/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:57:56 by mehernan          #+#    #+#             */
/*   Updated: 2022/06/07 16:46:59 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//guardar tanta memoria como la string tiene
//hacer la copia
//devolver el puntero en donde esta
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		count;

	count = 0;
	while (s1 [count] != '\0')
		count++;
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (NULL);
	count = 0;
	while (s1[count] != '\0')
	{
		ptr[count] = s1[count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}
