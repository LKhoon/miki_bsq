#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_BUF 1024
char	g_filename[] = "test.txt";

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

int lenfor_nextenter(int alreadyread)
{
    int		fd;
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

int	howmany_charbefore(int	rowindex)
{
	int		i;
	int		readstart;

	i = 1;
	readstart = 0;
	while(i < rowindex)
	{
		readstart += lenfor_nextenter(readstart);
		if (lenfor_nextenter(readstart) == -1)
			return (-1);
		++i;
	}
	return (readstart);
}

int rowlen(int	rowindex)
{
	int readstart;

	readstart = howmany_charbefore(rowindex);
	return (lenfor_nextenter(readstart) - 1);
}


char	*getcontents(int rowindex)
{
	char	buf[MAX_BUF];
	char	*contents;
	int		temp;
	int		count;
	int 	fd;

	contents = (char*)malloc(sizeof(char) * rowlen(rowindex) + 1);
	fd = open(g_filename, O_RDONLY);
	read(fd, buf, howmany_charbefore(rowindex));
	while ((temp = read(fd, buf, sizeof(buf))) > 0)
	{
		count = 0;
		while (buf[count] != '\n' && count < temp)
		{
			*contents = buf[count++];
			contents++;
		}
		if (buf[count] == '\n')
		{
			*contents = '\0';
			return (contents - rowlen(rowindex));
		}
	}
	return (0);
}


int main(void)
{
	printf("%d\n", rowlen(1));
	printf("%d\n", howmany_charbefore(3));
	printf("%s\n", getcontents(1));
}
