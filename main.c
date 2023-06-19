#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

int	main(void)
{
	void *img;
	void *mlx;
//	void *mlx_win;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello");
//	mlx_loop(mlx);
/*	int count = 0;

	if (argc > 2)
		return (0);
	while(argv[1][count] != '\0')
	{
		ft_printf("%c", argv[1][count]);
		count++;
	}
	return (0);*/
}
