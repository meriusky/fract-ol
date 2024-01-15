/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:00:30 by mehernan          #+#    #+#             */
/*   Updated: 2024/01/15 21:41:18 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	load_image(t_fract *f)
{
	int		x;
	int		y;
	int		iteration;
	float	x0;
	float	y0;

	x = -1;
	f->max_iteration = 50 * log10(f->zoom + 10);
	while (++x < 640)
	{
		y = -1;
		while (++y < 420)
		{
			x0 = ((float)x / 640.0) * (f->x_max - f->x_min) + f->x_min;
			y0 = ((float)y / 420.0) * (f->y_max - f->y_min) + f->y_min;
			if (f->parameter == 1)
				iteration = loop_mandelbrot(f, x0, y0);
			else
				iteration = loop_julia(f, x0, y0);
			color_grad(f, iteration, x, y);
		}
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img, 0, 0);
	f->block = 1;
	return (0);
}

void	init(t_fract *f)
{
	f->block = 0;
	f->x_max = 2.0;
	f->x_min = -2.0;
	f->y_max = 1.5;
	f->y_min = -1.5;
	f->zoom = 1.0;
	f->r_julia = 0.285;
	f->i_julia = -0.01;
}

int	warning(int i)
{
	if (i == 1)
		ft_printf("Just two options available: mandelbrot or julia\n");
	else if (i == 2)
		ft_printf("Arguments have to be between -2 and 2\n");
	else
		ft_printf("Arguments are not numbers\n");
	return (1);
}

int	check_arguments(int argc, char **argv, t_fract *f)
{
	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) != 0
			&& ft_strncmp(argv[1], "julia", 6) != 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 6) != 0)
		|| (argc != 2 && argc != 4))
		return (warning(1));
	if (argc == 4 && (ft_atof(argv[2], &f->r_julia)
			|| ft_atof(argv[3], &f->i_julia)))
		return (warning(3));
	f->parameter = 0;
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		f->parameter = 1;
	else
		if ((f->i_julia < -2 || f->i_julia > 2)
			|| (f->r_julia < -2 || f->r_julia > 2))
			return (warning(2));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fract	f;

	init(&f);
	if (check_arguments(argc, argv, &f) == 1)
		return (1);
	f.mlx = mlx_init();
	f.mlx_win = mlx_new_window(f.mlx, 640, 420, "fractol");
	f.img.img = mlx_new_image(f.mlx, 640, 420);
	f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bits_per_pixel, \
		&f.img.line_length, &f.img.endian);
	load_image(&f);
	mlx_key_hook(f.mlx_win, hook_keyboard, &f);
	mlx_mouse_hook(f.mlx_win, hook_mouse, &f);
	mlx_loop_hook(f.mlx, loop_hook, &f);
	mlx_hook(f.mlx_win, 17, 1L << 0, (void *)exit, &f);
	mlx_loop(f.mlx);
}
