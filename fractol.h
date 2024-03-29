/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:00:53 by mehernan          #+#    #+#             */
/*   Updated: 2024/01/15 21:04:57 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <math.h>
# include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fract
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		block;
	float	x_max;
	float	y_max;
	float	x_min;
	float	y_min;
	int		max_iteration;
	float	zoom;
	float	i_julia;
	float	r_julia;
	int		parameter;
}	t_fract;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	color_grad(t_fract *f, int i, int col, int row);
int		loop_mandelbrot(t_fract *f, float x0, float y0);
int		loop_julia(t_fract *f, float x0, float y0);
int		hook_mouse(int keycode, int x, int y, t_fract *f);
int		hook_keyboard(int keycode, t_fract *f);
int		loop_hook(t_fract *f);
int		load_image(t_fract *f);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
