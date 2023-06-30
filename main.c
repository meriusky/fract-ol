#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}t_data;

typedef struct	s_fract // en las estructuras podemos meter otras estructuras y muchas variables. Para organizar y no tener problemas con la norminette.
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	block;
}t_fract;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	hook_keyboard(int keycode, t_fract *f)//funcion que cierra con el esc y mas...
{
	(void)f;
	ft_printf("keycode: %d\n", keycode);
	if (keycode == 53)//para cerrar con el esc
		exit(0);
	return (0);
}
int	mandelbrot(t_fract *f)
{
	long x;
	long y;
	long x0;
	long y0;
	long xtemp;
	long iteration;
	long max_iteration;
	long color;
	 
	  x = 0;
	  y = 0;
	xtemp = 0;
	iteration = 0;
	max_iteration = 1000;
	while (x < 1280)
	 {
		while(y < 940)
		{
			x0 =  (x / 1280) * 4.0 - 2.0;
			y0 = (y / 940) * 4.0 - 2.0;
		 	 while (x*x + y*y <= (2*2) && iteration < max_iteration)
		  	{
		    		xtemp = x*x - y*y + x0;
		   		y = 2*x*y + y0;
		  		x = xtemp;
			 	iteration = iteration + 1;
		  	}
	  	if (iteration == max_iteration)
	   	 	color = 0;
	 	 else
	   		color = iteration;
		my_mlx_pixel_put(&f->img, x, y, color);
		y++;
		}
	x++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img, 0, 0);
	f->block = 1;
	return (0);
}

int	loop_hook(t_fract *f)//mandelbrot
{
	if (f->block == 0)
		mandelbrot(f);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fract	f;// para llamar las variables debemos poner un . para idicar que esta dentro(si no es un *), (si es * hay que poner ->)
//	int	i;

//	i = 5;
	f.block = 0;
	if(argc != 2 || ft_strncmp(argv[1], "do", 2) != 0)
	{
		ft_printf("you have to write do\n");
		return(0);
	}
	f.mlx = mlx_init();
	f.mlx_win = mlx_new_window(f.mlx, 1280, 940, "hello");
	f.img.img = mlx_new_image(f.mlx, 1280, 940);
	f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bits_per_pixel, &f.img.line_length, &f.img.endian);
//   	while (++i < 300)
//		my_mlx_pixel_put(&f.img, i, 5, 0x00FF0000);
//	mlx_put_image_to_window(f.mlx, f.mlx_win, f.img.img, 0, 0);
//aqui se debe crear los hooks (funcion para hacer lo del esc y que se cierre, o en verdad cualquier cosa con el raton o las teclas y que haga algo para hacer lo del esc y que se cierre, o en verdad cualquier cosa con el raton o las teclas y que haga algo))
	mandelbrot(&f);
	mlx_key_hook(f.mlx_win, hook_keyboard, &f);
	mlx_loop_hook(f.mlx, loop_hook, &f);
	mlx_loop(f.mlx);//funcion que hace correr infinitamente la imagen
}
