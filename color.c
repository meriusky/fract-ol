/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:53:38 by mehernan          #+#    #+#             */
/*   Updated: 2024/01/15 21:00:22 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	*assign_rgb(float r, float g, float b)
{
	int	*rgb;

	rgb = malloc(sizeof(int) * 3);
	rgb[0] = (int)(r * 255);
	rgb[1] = (int)(g * 255);
	rgb[2] = (int)(b * 255);
	return (rgb);
}

int	*hsv_to_rgb(float h, float s, float v)
{
	int		*rgb;
	float	values[5];

	values[0] = floor(h * 6);
	values[1] = (h * 6) - values[0];
	values[2] = v * (1 - s);
	values[3] = v * (1 - (values[1] * s));
	values[4] = v * (1 - ((1 - values[1]) * s));
	if (((int)values[0] % 6) == 0)
		rgb = assign_rgb(v, values[4], values[2]);
	if (((int)values[0] % 6) == 1)
		rgb = assign_rgb(values[3], v, values[2]);
	if (((int)values[0] % 6) == 2)
		rgb = assign_rgb(values[2], v, values[4]);
	if (((int)values[0] % 6) == 3)
		rgb = assign_rgb(values[2], values[3], v);
	if (((int)values[0] % 6) == 4)
		rgb = assign_rgb(values[4], values[2], v);
	if (((int)values[0] % 6) == 5)
		rgb = assign_rgb(v, values[2], values[3]);
	return (rgb);
}

void	color_grad(t_fract *f, int i, int col, int row)
{
	int		*rgb;
	float	light;

	light = (float)i / (float)f->max_iteration;
	if (i < f->max_iteration)
		rgb = hsv_to_rgb(light, 1.0, 1.0);
	else
		rgb = hsv_to_rgb(360, 1.0, 0.0);
	my_mlx_pixel_put(&f->img, col, row, (((0 & 0xff) << 24) + \
	((rgb[0] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + ((rgb[2] & 0xff))));
	free(rgb);
}
