#include "common.h"
#include "readfile.h"

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

int		*bsq(int **grid_bsq, char **grid_map, int *bslocation, int collen, char *symbol)
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
			if (grid_map[col - 1][row - 1] == symbol[0])
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

void	mark_square(char **grid_map, int **grid_bsq, char *symbol, int *bslocation)
{
	int	bssize;
	int	row_now;
	int	col_now;
	int	row_end_vertex;
	int	col_end_vertex;

	bssize = grid_bsq[bslocation[0]][bslocation[1]];
	col_now = bslocation[0] - bssize;
	col_end_vertex = bslocation[0] - 1;
	row_end_vertex = bslocation[1] - 1;
	while (col_now <= col_end_vertex)
	{
		row_now = bslocation[1] - bssize;
		while (row_now <= row_end_vertex)
		{
			grid_map[col_now][row_now] = symbol[2];
			++row_now;
		}
		++col_now;
	}
}
