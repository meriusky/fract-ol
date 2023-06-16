/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:29:59 by mehernan          #+#    #+#             */
/*   Updated: 2022/10/10 19:07:03 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	filter(char f, va_list args)
{
	if (f == 'c')
		return (ft_character(va_arg(args, int)));
	else if (f == 's')
		return (ft_string(va_arg(args, char *)));
	else if (f == 'p')
		return (ft_pointer(va_arg(args, unsigned long long)));
	else if (f == 'd' || f == 'i')
		return (ft_decimal(va_arg(args, int)));
	else if (f == 'u')
		return (ft_num_no_sign(va_arg(args, unsigned int)));
	else if (f == 'x')
		return (ft_hexadecimal_min(va_arg(args, unsigned int)));
	else if (f == 'X')
		return (ft_hexadecimal_cap(va_arg(args, unsigned int)));
	else
		return (ft_character(f));
}
