#include "bsqheader.h"

char	gg_filename[] = "test.txt";

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

int		lenfor_nextenter(int alreadyread)
{
    int		fd;
	int     count;
    int     result;
    int     temp;
    char    buf[MAX_BUF];

	result = 0;
	fd = open(gg_filename, O_RDONLY);
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

int		howmany_charbefore(int	rowindex)
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

int		rowlen(int	rowindex)
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
	fd = open(gg_filename, O_RDONLY);
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

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		collen(void)
{
	int		start;
	int		end;
	int		num;
	char	*firstrow_contents;

	firstrow_contents = getcontents(1);
	start = 0;
	end = rowlen(1) - 4;
	num = 0;
	while (start <= end)
	{
		if (!is_number(firstrow_contents[start]))
			return (-1);
		else
		{
			num = num * 10 + firstrow_contents[start++] - '0';
		}
	}
	return (num);
}

void	getsymbol(char *symbol)
{
	int		end;
	char	*firstrow_contents;

	firstrow_contents = getcontents(1);
	end = rowlen(1) - 1;
	symbol[2] = firstrow_contents[end];
	symbol[1] = firstrow_contents[end - 2];
	symbol[0] = firstrow_contents[end - 1];
}

int		symboltoint(char *symbol, char c)
{
	int		i;

	i = 0;
	while (i <= 2)
	{
		if (c == symbol[i])
			return (i);
		i++;
	}
	return (-1);
}

void	fillgrid(int	**grid_map, char *symbol)
{
	int		col;
	int		row;
	int		col_end;
	int		row_end;
	char	*currentrow;

	col = 0;
	col_end = collen();
	row_end = rowlen(2);
	while (col < col_end)
	{
		currentrow = getcontents(col + 2); // mapfile의 두번 째 행부터 읽어야하니까
		row = 0;
		while(row < row_end)
		{
			grid_map[col][row] = symboltoint(symbol, currentrow[row]);
			++row;
		}
		++col;
	}
}

// int main(void)
// {
// 	int	**grid_test;
// 	char symbol[3];

// 	grid_test = gridinit(collen(),rowlen(2));
// 	getsymbol(symbol);
// 	fillgrid(grid_test, symbol);

// 	printf("%d\n", rowlen(2));
// 	printf("%d\n", howmany_charbefore(3));
// 	printf("%s\n", getcontents(1));
// 	printf("%d\n", collen());
// 	printf("%c\n", symbol[2]);
// 	int col = 0;
// 	int row;

// 	while (col < collen())
// 	{
// 		row = 0;
// 		while (row < rowlen(2))
// 		{
// 			printf("%d",grid_test[col][row]);
// 			row++;
// 		}
// 		printf("\n");
// 		col++;
// 	}
// }
