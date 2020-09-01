#include "common.h"
#include "readfile.h"

void	print_bsq(char **grid_map, int collen)
{
	int col = 0;

	while (col < collen)
	{
		write (1, grid_map[col], get_rowlen(2) + 1);
		col++;
	}
}
