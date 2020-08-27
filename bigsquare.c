#include "bsqheader.h"

int		minval(int left, int lefttop, int top)
{
	int min;

	min = left;
	if (lefttop < min)
		min = lefttop;
	if (top < min)
		min = top;
	return (min);
}

int		*bsq(int **grid_bsq, int **grid_map, int *bslocation)
{
	int row;
	int col;
	int	biggest;

	col = 1;
	biggest = 0;
	while (col <= collen())
	{
		row = 1;
		while (row <= rowlen(2))
		{
			if (grid_map[col - 1][row - 1] == 0)
				grid_bsq[col][row] = 0;
			else
			{
				grid_bsq[col][row] = minval(grid_bsq[col][row - 1],
				grid_bsq[col - 1][row - 1], grid_bsq[col - 1][row]) + 1;
				if (grid_bsq[col][row] > biggest)
				{
					biggest = grid_bsq[col][row];
					bslocation[0] = col;
					bslocation[1] = row;
				}
			}
			++row;
		}
		++col;
	}
	return (bslocation);
}
