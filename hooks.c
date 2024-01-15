/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:41:49 by mehernan          #+#    #+#             */
/*   Updated: 2024/01/15 21:07:41 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	hook_mouse(int keycode, int x, int y, t_fract *f)
{
	float	x_percent;
	float	y_percent;

	(void)x;
	(void)y;
	x_percent = (f->x_max - f->x_min) / 100 * 2;
	y_percent = (f->y_max - f->y_min) / 100 * 2;
	f->block = 0;
	if (keycode == 4)
	{
		f->x_max = f->x_max - x_percent;
		f->x_min = f->x_min + x_percent;
		f->y_max = f->y_max - y_percent;
		f->y_min = f->y_min + y_percent;
		f->zoom = f->zoom * 1.25;
	}
	else if (keycode == 5)
	{
		f->x_max = f->x_max + x_percent;
		f->x_min = f->x_min - x_percent;
		f->y_max = f->y_max + y_percent;
		f->y_min = f->y_min - y_percent;
		f->zoom = f->zoom / 1.25;
	}
	return (0);
}

int	hook_keyboard_pt2(int keycode, t_fract *f, float x_percent)
{
	if (keycode == 124)
	{
		f->x_max = f->x_max + x_percent;
		f->x_min = f->x_min + x_percent;
		f->block = 0;
	}
	else if (keycode == 123)
	{
		f->x_max = f->x_max - x_percent;
		f->x_min = f->x_min - x_percent;
		f->block = 0;
	}
	return (0);
}

int	hook_keyboard(int keycode, t_fract *f)
{
	float	x_percent;
	float	y_percent;

	f->block = 0;
	x_percent = (f->x_max - f->x_min) / 100 * 2;
	y_percent = (f->y_max - f->y_min) / 100 * 2;
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
	{
		f->y_max = f->y_max - y_percent;
		f->y_min = f->y_min - y_percent;
		f->block = 0;
	}
	else if (keycode == 125)
	{
		f->y_max = f->y_max + y_percent;
		f->y_min = f->y_min + y_percent;
		f->block = 0;
	}
	else
		hook_keyboard_pt2(keycode, f, x_percent);
	return (0);
}

int	loop_hook(t_fract *f)
{
	if (f->block == 0)
		load_image(f);
	return (0);
}
