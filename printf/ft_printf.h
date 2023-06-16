/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:18:05 by mehernan          #+#    #+#             */
/*   Updated: 2022/10/10 18:59:13 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_character(char c);
int		ft_string(const char *s);
int		ft_pointer(unsigned long long p);
int		ft_decimal(int d);
int		ft_num_no_sign(unsigned int u);
int		ft_hexadecimal_min(unsigned int x);
int		ft_hexadecimal_cap(unsigned int bigx);
int		filter(char f, va_list args);
int		ft_printf(char const *pf, ...);

#endif
