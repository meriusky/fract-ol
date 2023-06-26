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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char *argv[])
{
	void *mlx;
	void *mlx_win;
	t_data img;
	int	i;

	i = 5;
	if(argc != 2 || ft_strncmp(argv[1], "do", 2) != 0)
	{
		ft_printf("you have to write do\n");
		return(0);
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
   	while (++i < 300)
		my_mlx_pixel_put(&img, i, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
