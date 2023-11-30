/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:45:24 by mehernan          #+#    #+#             */
/*   Updated: 2023/11/30 17:11:50 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atof(const char *str, double *value)
{
	int		sign = 1;
	double	multiplier = 0.1;
	double	result = 0.0;
	double	fraction = 0.0;
	
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
		else
			sign = 1;
	}
	if (!ft_isdigit(*str))
		 return (1);
	while (ft_isdigit(*str))
		result = result * 10.0 + (*str++ - '0');
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
	if (sign == -1)
		result *= sign;
	*value = result + fraction;
	return (0);
}
