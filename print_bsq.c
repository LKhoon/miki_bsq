#include "bsqheader.h"

int		*find_start(int **grid_bsq, int *bslocation)
{
	int	y;
	int	x;
	int	*result;

	result = (int *)malloc(sizeof(int) * 2);
	y = bslocation[0];
	x = bslocation[1];
	while (x >= 0 && y >= 0)
	{
		if (grid_bsq[bslocation[0]][x] == 0 || grid_bsq[y][bslocation[1]] == 0)
			break ;
		x--;
		y--;
	}
	result[0] = bslocation[0] - (bslocation[1] - x);
	result[1] = bslocation[1] - (bslocation[1] - x);
	return (result);
}

// bslocation[0] = y, bslocation[1] = x
// 되는지 확인안해봄...
void	print_bsq(int **grid_bsq, char *symbol, int *bslocation)
{
	int	*start;
	int	i;
	int	j;
	int	row;
	int	col;

	row = rowlen(2);
	col = collen();
	start = find_start(grid_bsq, bslocation);
	i = 1;
	j = 1;
	while (j <= col)
	{
		while (i <= row)
		{
			if (j >= start[0] && j <= bslocation[0] && i >= start[1] && i <= bslocation[1])
				write(1, &symbol[2], 1);
			else
				write(1, &symbol[grid_bsq[j][i]], 1);
		}
		write(1, "\n", 1);
	}
}