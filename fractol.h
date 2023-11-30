#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
#include <math.h>
#include <stdio.h>
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
	float	x_max;
	float	y_max;
	float	x_min;
	float	y_min;
	int	max_iteration;
	float	zoom;
	float	i_julia;
	float	r_julia;
	int	parameter;

}t_fract;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    color_grad(t_fract *f, int i, int col, int row);
#endif
