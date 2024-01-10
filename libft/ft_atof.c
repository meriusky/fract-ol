/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:45:24 by mehernan          #+#    #+#             */
/*   Updated: 2024/01/10 13:18:58 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atof(const char *str, float *value)
{
	float	sign = 1.00;
	float	multiplier = 0.1;
	float	result = 0.0;
	float	fraction = 0.0;
	
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1.00;
	}
	if (!ft_isdigit(*str))
		 return (1);
	while (ft_isdigit(*str))
		result = result * 10.0 + (*str++ - '0');
	if (*str != '\0')
	{
		if (*str != '.' && !ft_isdigit(*str))
			return (1);
		str++;
		while (ft_isdigit(*str))
		{
			fraction += (*str++ - '0') * multiplier;
			multiplier *= 0.1;
		}
		if (*str != '\0')
			return (1);
		if (sign == -1.00)
		{
			if (result == 0.00)
				fraction *= sign;
			else
				result *= sign;
		}
	}
	*value = result + fraction;
	return (0);
}
