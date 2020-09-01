#ifndef BSQ_H
# define BSQ_H

int		**init_grid_bsq(int collen, int rowlen);
char	**init_grid_map(int collen);
int		minval(int **grid_bsq, int col, int row);
int		*bsq(int **grid_bsq, char **grid_map, int *bslocation, int collen, char *symbol);
void	mark_square(char **grid_map, int **grid_bsq, char *symbol, int *bslocation);

#endif
