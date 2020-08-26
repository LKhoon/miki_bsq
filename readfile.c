#include "bsqheader.h"

int		**gridinit(int collen, int rowlen)
{
	int **grid;
	int i;

	grid = (int**)malloc(sizeof(int*) * collen);
	i = 0;
	while (i < collen)
	{
		grid[i] = (int*)malloc(sizeof(int) * rowlen);
		i++;
	}
	return (grid);
}

int readnext(int alreadyread)
{
	int 	fd;
    int     count;
    int     result;
    int     temp;
    char    buf[MAX_BUF];
    result = 0;

	fd = open(g_filename, O_RDONLY);
	read(fd, buf, alreadyread);
    while ((temp = read(fd, buf, sizeof(buf))) > 0)
    {
        count = 0;
        while (buf[count] != '\n' && count < temp)
        {
            count++;
            result++;
        }
        if (buf[count] == '\n')
            return (result + 1);
    }
    return (-1);
}

int rowlen(int	rowindex)
{
	int alreadyread;
	int i;

	i = 1;
	alreadyread = 0;
	while(i < rowindex)
	{
		alreadyread += readnext(alreadyread);
		++i;
	}
	return (readnext(alreadyread) - 1);
}

int main(void)
{
	printf("%d", rowlen(17));
}
