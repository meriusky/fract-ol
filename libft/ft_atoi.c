/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:45:24 by mehernan          #+#    #+#             */
/*   Updated: 2023/05/25 16:30:13 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_if_number(int count, int length)
{
	if (count != length)
	{
		write(1, "PID has to be a number\n", 23);
		exit(0);
	}
}

int	ft_atoi(const char *str)
{
	int	count;
	int	num;
	int	sign;
	int	length;

	count = 0;
	num = 0;
	sign = 1;
	length = ft_strlen(str);
	while (str[count] == '\t' || str[count] == '\f' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\v' || str[count] == ' ')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		num = (num * 10) + (str[count] - '0');
		count++;
	}
	check_if_number(count, length);
	return (num * sign);
}
