#include <unistd.h>

int	main(int argc, char *argv[])
{
	int count = 0;

	if (argc > 2)
		return (0);
	while(argv[1][count] != '\0')
	{
		write(1, &argv[1][count], 1);
		count++;
	}
	return (0);
}
