#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	int count = 0;

	if (argc > 2)
		return (0);
	while(argv[1][count] != '\0')
	{
		ft_printf("%c", argv[1][count]);
		count++;
	}
	return (0);
}
