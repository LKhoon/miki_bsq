#ifndef BSQ_H
# define BSQ_H

int		**init_grid_bsq(int collen, int rowlen);
char	**init_grid_map(int collen);
int		minval(int **bs, int col, int row);
int		*bsq(int **bs, char **map, int *bsl, int collen, char *symbol);
void	mark_square(char **map, int **bs, char *symbol, int *bsl);

#endif
