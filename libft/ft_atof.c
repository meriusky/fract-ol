/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:45:24 by mehernan          #+#    #+#             */
/*   Updated: 2024/01/15 22:48:33 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atof_pt2(float *multiplier, float *fraction, char *str)
{
	if (*str != '\0')
	{
		if (*str != '.' && !ft_isdigit(*str))
			return (1);
		str++;
		while (ft_isdigit(*str))
		{
			*fraction += (*str++ - '0') * *multiplier;
			*multiplier *= 0.1;
		}
		if (*str != '\0')
			return (1);
	}
	return (0);
}

int	check_values(char **str, float *sign)
{
	if (*str[0] == '-' || *str[0] == '+')
	{
		if (*str[0] == '-')
			*sign = -1.00;
		(*str)++;
	}
	if (!ft_isdigit(*str[0]))
		return (1);
	return (0);
}

int	ft_atof(char *str, float *value)
{
	float	sign;
	float	result;
	float	fraction;
	float	multiplier;

	sign = 1.0;
	result = 0.0;
	fraction = 0.0;
	multiplier = 0.1;
	if (check_values(&str, &sign) == 1)
		return (1);
	while (ft_isdigit(*str))
		result = result * 10.0 + (*str++ - '0');
	if (*str != '\0' && ft_atof_pt2(&multiplier, &fraction, str) == 1)
		return (1);
	if (sign == -1.00)
	{
		if (result == 0.00)
			fraction *= sign;
		else
			result *= sign;
	}
	*value = result + fraction;
	return (0);
}
