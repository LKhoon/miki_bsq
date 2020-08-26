#include <unistd.h>
#include <fcntl.h>

char	*ft_fgets(char *str, int num, char *currentfile)
{
	int		fd;

	fd = open(currentfile, O_RDONLY);

}
