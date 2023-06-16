/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:33:06 by mehernan          #+#    #+#             */
/*   Updated: 2022/11/27 19:54:56 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_mem_case_error(char **result, int i)
{
	int	count;

	count = 0;
	while (count < i)
	{
		free(result[count]);
		count++;
	}
	free(result);
}	

char	**construct_result(char **result, char const *s, char c)
{
	int		count;
	int		start;
	int		i;

	count = -1;
	i = 0;
	start = 0;
	while (s[++count] != '\0')
	{
		if (s[count] == c && s[count + 1] != c)
			start = count + 1;
		if (s[count] != c && (s[count + 1] == c || s[count + 1] == '\0'))
		{
			result[i] = ft_substr(s, start, count - start + 1);
			if (!result[i])
			{
				free_mem_case_error(result, i);
				return (NULL);
			}
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

int	contar_palabras(char const *s, char c)
{
	int	num_palabras;
	int	count;

	num_palabras = 0;
	count = 0;
	while (s[count])
	{
		if (s[count] != c && (s[count + 1] == c || s[count + 1] == '\0'))
			num_palabras++;
		count++;
	}
	return (num_palabras);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		num_palabras;

	num_palabras = contar_palabras(s, c);
	result = malloc(sizeof(char *) * (num_palabras + 1));
	if (!result)
		return (NULL);
	result = construct_result(result, s, c);
	return (result);
}
