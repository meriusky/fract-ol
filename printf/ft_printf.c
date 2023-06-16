/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:30:19 by mehernan          #+#    #+#             */
/*   Updated: 2022/10/11 17:49:49 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check_filter(char c, int *savef, va_list args)
{
	int	ret;

	ret = filter(c, args);
	if (ret == -1)
		return (-1);
	*savef = *savef + ret;
	return (1);
}

int	continued(int *count, int *savef, char character)
{
	if (ft_character(character) == -1)
		return (-1);
	*savef = *savef + 1;
	*count = *count + 1;
	return (1);
}

int	ft_printf(char const *pf, ...)
{
	va_list	args;
	int		count;
	int		savef;

	count = 0;
	savef = 0;
	va_start (args, pf);
	while (pf[count])
	{
		if (pf[count] == '%')
		{
			count++;
			if (check_filter(pf[count], &savef, args) == -1)
				return (-1);
			count++;
		}
		else
		{
			if (continued(&count, &savef, pf[count]) == -1)
				return (-1);
		}
	}
	va_end (args);
	return (savef);
}
