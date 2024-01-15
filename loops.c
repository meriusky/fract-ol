/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:46:53 by mehernan          #+#    #+#             */
/*   Updated: 2024/01/15 18:45:35 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_mandelbrot(t_fract *f, float x0, float y0)
{
	int		iteration;
	float	x;
	float	y;
	float	xtemp;

	x = 0.0;
	y = 0.0;
	iteration = 0;
	while (x * x + y * y <= (2 * 2) && iteration < f->max_iteration)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}

int	loop_julia(t_fract *f, float x0, float y0)
{
	int		iteration;
	float	xtemp;

	iteration = 0;
	while (x0 * x0 + y0 * y0 <= (2 * 2) && iteration < f->max_iteration)
	{
		xtemp = x0 * x0 - y0 * y0 + f->r_julia;
		y0 = 2 * x0 * y0 + f->i_julia;
		x0 = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}
