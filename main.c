#include "fractol.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	hook_mouse(int keycode, int x, int y, t_fract *f)
{
	float	x_percent;
	float	y_percent;

	x = 0;
	y = 0;
	x_percent = (f->x_max - f->x_min) / 100 * 2;
	y_percent = (f->y_max - f->y_min) / 100 * 2;
	f->block = 0;
	if (keycode == 4)//zoom in por eso I que es 34 (cambiar a rueda del raton)
	{
		f->x_max = f->x_max - x_percent;
		f->x_min = f->x_min + x_percent;
		f->y_max = f->y_max - y_percent;
		f->y_min = f->y_min + y_percent;
		f->zoom = f->zoom * 1.25;
	}
	else if (keycode == 5)//zoom out por eso O que es 31
	{
		f->x_max = f->x_max + x_percent;
		f->x_min = f->x_min - x_percent;
		f->y_max = f->y_max + y_percent;
		f->y_min = f->y_min - y_percent;
		f->zoom = f->zoom / 1.25;
	}
	return (0);
}

int	hook_keyboard(int keycode, t_fract *f)//funcion que cierra con el esc y mas...
{
	float	x_percent;
	float	y_percent;

	f->block = 0;
	x_percent = (f->x_max - f->x_min) / 100 * 2;
	y_percent = (f->y_max - f->y_min) / 100 * 2;
	ft_printf("keycode: %d\t%p\n", keycode, f);
	if (keycode == 53)//para cerrar con el esc
		exit(0);
	else if (keycode == 126)//arriba
	{
		f->y_max = f->y_max - y_percent;
		f->y_min = f->y_min - y_percent;
		f->block = 0;
	}
	else if (keycode == 125)//abajo
	{
		f->y_max = f->y_max + y_percent;
		f->y_min = f->y_min + y_percent;
		f->block = 0;
	}
	else if (keycode == 124)//derecha
	{
		f->x_max = f->x_max + x_percent;
		f->x_min = f->x_min + x_percent;
		f->block = 0;
	}
	else if (keycode == 123)//izquierda
	{
		f->x_max = f->x_max - x_percent;
		f->x_min = f->x_min - x_percent;
		f->block = 0;
	}
	return (0);
}

int    loop_mandelbrot(t_fract *f, float x0, float y0)//float es la manera en la que se declaran los numeros con decimales
{
    int        iteration;
    float    x;
    float    y;
    float    xtemp;
	
	x = 0.0;
	y = 0.0;
    iteration = 0;
    while (x*x + y*y <= (2*2) && iteration < f->max_iteration)
    {
		xtemp = x*x - y*y + x0;
		y = 2*x*y + y0;
		x = xtemp;
		iteration = iteration + 1;
    }
    return (iteration);
}

int    loop_julia(t_fract *f, float x0, float y0)
{
    int        iteration;
    float    xtemp;

    iteration = 0;
    while (x0*x0 + y0*y0 <= (2*2) && iteration < f->max_iteration)
    {
        xtemp = x0*x0 - y0*y0 + f->r_julia;
        y0 = 2*x0*y0 + f->i_julia;
        x0 = xtemp;
        iteration = iteration + 1;
    }
    return (iteration);
}

int    load_image(t_fract *f)//CAMBIAR NOMBREEEEE
{
    int        x;
    int        y;
    int		iteration;
    float    x0;
    float    y0;

    x = 0;
    f->max_iteration = 50 * log10(f->zoom + 10);
    printf("%d\n",f->max_iteration);
    while (x < 1280)
    {
        y = 0;
        while (y < 940)
        {
            x0 =  ((float)x / 1280.0) * (f->x_max - f->x_min) + f->x_min;
            y0 = ((float)y / 940.0) * (f->y_max - f->y_min) + f->y_min;
//			if (par == 1)
				 iteration = loop_mandelbrot(f, x0, y0);	
//			else
//				iteration = loop_julia(f, x0, y0);
           // iteration = loop_mandelbrot(f, x0, y0);//o mandelbrot o julia
			color_grad(f, iteration, x, y);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img, 0, 0);
    f->block = 1;
    return (0);
}

int	loop_hook(t_fract *f)//funcion que se repite hasta el infinito hasta que el programa termina
{
	if (f->block == 0)
		load_image(f);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fract	f;// para llamar las variables debemos poner un . para idicar que esta dentro(si no es un *), (si es * hay que poner ->)
//	int	i;

//	i = 5;
	f.block = 0;
	f.x_max = 2.0;
	f.x_min = -2.0;
	f.y_max = 1.5;
	f.y_min = -1.5;
	f.zoom = 1.0;
	f.i_julia = -0.01;
	f.r_julia = 0.285;
	if(argc != 2 || (ft_strncmp(argv[1], "mandelbrot", 10) != 0 && ft_strncmp(argv[1], "julia", 5) != 0) && (ft_strlen(argv[1]) != 11 || ft_strlen(argv[1]) != 7)) 
	{
		//if(ft_strlen(argv[1]) != 10 || ft_strlen(argv[1]) != 6)
			ft_printf("Just two options available: madelbrot or julia\n");
		return(0);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		f.parameter = 1;
	f.mlx = mlx_init();
	f.mlx_win = mlx_new_window(f.mlx, 1280, 940, "fractol");
	f.img.img = mlx_new_image(f.mlx, 1280, 940);
	f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bits_per_pixel, &f.img.line_length, &f.img.endian);
//   	while (++i < 300)
//		my_mlx_pixel_put(&f.img, i, 5, 0x00FF0000);
//	mlx_put_image_to_window(f.mlx, f.mlx_win, f.img.img, 0, 0);
//aqui se debe crear los hooks (funcion para hacer lo del esc y que se cierre, o en verdad cualquier cosa con el raton o las teclas)
	load_image(&f);
	mlx_key_hook(f.mlx_win, hook_keyboard, &f);
	mlx_mouse_hook(f.mlx_win, hook_mouse, &f);//lo del raton
	mlx_loop_hook(f.mlx, loop_hook, &f);
	mlx_loop(f.mlx);//funcion que hace correr infinitamente la imagen
}
