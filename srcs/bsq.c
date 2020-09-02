#include "common.h"

int		**init_grid_bsq(int collen, int rowlen)
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
		if ((grid[i] = (int*)malloc(sizeof(int) * rowlen)) < 0)
		{
			write(1, "malloc Error\n", 13);
			return (0);
		}
		i++;
	}
	return (grid);
}

char	**init_grid_map(int collen)
{
	char	**grid;
	int		col;
	int		fd;
	int		row_max;

	row_max = 0;
	fd = open(g_filename, O_RDONLY);
	if ((grid = (char**)malloc(sizeof(char*) * collen)) < 0)
		return (0);
	col = 0;
	row_max = get_rowlen(2);
	read_iter(fd, get_rowlen(1) + 1);
	while (col < collen)
	{
		if ((grid[col] = (char*)malloc(sizeof(char) * row_max + 1)) < 0)
			return (0);
		read(fd, grid[col], row_max + 1);
		col++;
	}
	close(fd);
	return (grid);
}

int		minval(int **bs, int col, int row)
{
	int		min;
	int		left;
	int		left_top;
	int		top;

	left = bs[col][row - 1];
	left_top = bs[col - 1][row - 1];
	top = bs[col - 1][row];
	min = left;
	if (left_top < min)
		min = left_top;
	if (top < min)
		min = top;
	return (min);
}

int		*bsq(int **bs, char **map, int *bsl, int collen, char *symbol)
{
	int row;
	int col;
	int	biggest;
	int rowlen;

	rowlen = get_rowlen(2);
	col = 0;
	biggest = 0;
	while (++col <= collen)
	{
		row = 0;
		while (++row <= rowlen)
		{
			bs[col][row] = (map[col - 1][row - 1] == symbol[0])
			? 0 : minval(bs, col, row) + 1;
			if (bs[col][row] > biggest)
			{
				biggest = bs[col][row];
				bsl[0] = col;
				bsl[1] = row;
			}
		}
	}
	return (bsl);
}

void	mark_square(char **map, int **bs, char *symbol, int *bsl)
{
	int	bssize;
	int	row_now;
	int	col_now;
	int	row_end_vertex;
	int	col_end_vertex;

	bssize = bs[bsl[0]][bsl[1]];
	col_now = bsl[0] - bssize;
	col_end_vertex = bsl[0] - 1;
	row_end_vertex = bsl[1] - 1;
	while (col_now <= col_end_vertex)
	{
		row_now = bsl[1] - bssize;
		while (row_now <= row_end_vertex)
		{
			map[col_now][row_now] = symbol[2];
			++row_now;
		}
		++col_now;
	}
}
