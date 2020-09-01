#include "bsqheader.h"

int		**gridinit(int collen, int rowlen)
{
	int **grid;
	int i;

	if ((grid = (int**)malloc(sizeof(int*) * collen)) < 0)
	{
		write(1, "malloc Error\n", 13);
		return (0);
	}
	i = 0;
	while (i < collen)
	{
		if((grid[i] = (int*)malloc(sizeof(int) * rowlen)) < 0)
		{
			write(1, "malloc Error\n", 13);
			return (0);
		}
		i++;
	}
	return (grid);
}

void	read_iter(int fd, int alreadyread)
{
	char *buf[MAX_BUF];

	while (alreadyread > 1024)					//// *에러 요인 파악, read 함수에 1024 이상 size 값 들어가면 프로그램 종료됨.
	{
		read(fd, buf, 1024);
		alreadyread -= 1024;
	}
	read(fd, buf, alreadyread);
}

int		lenfor_nextenter(int alreadyread)
{
	int		fd;
	int	 count;
	int	 result;
	int	 temp;
	char	buf[MAX_BUF];

	result = 0;
	fd = open(g_filename, O_RDONLY);
	read_iter(fd, alreadyread);
	while ((temp = read(fd, buf, sizeof(buf))) > 0)
	{
		count = 0;
		while (buf[count] != '\n' && count < temp)
		{
			count++;
			result++;
		}
		if (buf[count] == '\n')
		{
			close(fd);
			return (result + 1);
		}
	}
	close(fd);
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
	fd = open(g_filename, O_RDONLY);
	read_iter(fd, howmany_charbefore(rowindex));
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
			close(fd);
			return (contents - rowlen(rowindex));
		}
	}
	close(fd);
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
	int		len;

	len = rowlen(1);
	firstrow_contents = getcontents(1);
	end = len - 1;
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

void	fillgrid(int **grid_map, char *symbol)
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
			if (grid_map[col][row] == -1)
				printf("GRIDMAP GET -1!!! ");
			++row;
		}
		free(currentrow);
		++col;
	}
}

int		minval(int **grid_bsq, int col, int row)
{
	int		min;
	int		left;
	int		left_top;
	int		top;

	left = grid_bsq[col][row - 1];
	left_top = grid_bsq[col - 1][row - 1];
	top = grid_bsq[col - 1][row];
	min = left;
	if (left_top < min)
		min = left_top;
	if (top < min)
		min = top;
	return (min);
}

int		*bsq(int **grid_bsq, int **grid_map, int *bslocation)
{
	int row;
	int col;
	int	biggest;

	col = 0;
	biggest = 0;
	while (++col <= collen())
	{
		row = 0;
		while (++row <= rowlen(2))
		{
			if (grid_map[col - 1][row - 1] == 0)
				grid_bsq[col][row] = 0;
			else
				grid_bsq[col][row] = minval(grid_bsq, col, row) + 1;
			if (grid_bsq[col][row] > biggest)
			{
				biggest = grid_bsq[col][row];
				bslocation[0] = col;
				bslocation[1] = row;
			}
		}
	}
	return (bslocation);
}

void	print





int main(void)
{
	int	**grid_map;
	int **grid_bsq;
	char symbol[3];
	int bslocation[2];
	int n;
	n = 70;
	int *ptr;
	ptr = (int *)malloc(sizeof(int) * 2);
	// int i = 0;
	// ptr[4] = 30;
	// while (i < 5)
	// 	printf("%d\n", ptr[i++]);
	// while (i < 257060)
	// 	ptr[i++] = 50;

	getsymbol(symbol);
	printf("[TEST1]first row length is :%d\n", rowlen(1));
	printf("[TEST2]second row length is :%d\n", rowlen(2));
	printf("[TEST3]second length contents is :%c,%c,%c\n", getcontents(2)[0], getcontents(2)[1], getcontents(2)[2]);
	printf("[TEST4]collum length is : %d\n", collen());
	printf("[TEST5]check symbol : %s (barrier,space,fill)\n", symbol);
	printf("[TEST6]howmany_char before last row is :%d\n", howmany_charbefore(n));

	grid_map = gridinit(collen(), rowlen(2));
	grid_bsq = gridinit(collen() + 1, rowlen(2) + 1);

	printf("[TEST7]grid init check: 0 is ok :%d\n", grid_map[n-1][n-1]);
	printf("[TEST8]grid init check: 0 is ok :%d\n", grid_bsq[n][n]);

	fillgrid(grid_map, symbol);
	bsq(grid_bsq, grid_map, bslocation);

	printf("[TEST9]The bslocation is : %d, %d \n", bslocation[0], bslocation[1]);
	printf("[TEST10]The bigsquare size is : %d \n", grid_bsq[bslocation[0]][bslocation[1]]);
	printf("[TEST11]the last element of grid_map :%d \n",grid_map[n - 1][n - 1]);
	printf("[TEST12]the last element of grid_bsq :%d \n",grid_bsq[n][n]);
	//grid_map 출력 테스트
	int col = 0;
	int row;

	while (col < collen())
	{
		row = 0;
		while (row < rowlen(2))
		{
			printf("%d",grid_map[col][row]);
			row++;
		}
		printf("\n");
		col++;
	}

	printf("\n\n\n");
	//grid_bsq 출력 테스트
	col = 1;

	while (col <= collen())
	{
		row = 1;
		while (row <= rowlen(2))
		{
			printf("%d",grid_bsq[col][row]);
			row++;
		}
		printf("\n");
		col++;
	}
	free(grid_bsq);
	free(grid_map);
}
