
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
