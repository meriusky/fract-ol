/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:01:41 by mehernan          #+#    #+#             */
/*   Updated: 2022/06/07 16:47:02 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	size_t	count;
	size_t	size_s1;
	size_t	size_s2;

	count = 0;
	if (!s1)
		s1 = "";
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	snew = (char *)malloc (sizeof(char) * (size_s1 + size_s2 + 1));
	if (snew == NULL)
		return (NULL);
	while (count++ < size_s1)
		snew[count - 1] = s1[count - 1];
	count = 0;
	while (count++ < size_s2)
		snew[size_s1 + count - 1] = s2[count - 1];
	snew [size_s1 + count - 1] = '\0';
	return (snew);
}
