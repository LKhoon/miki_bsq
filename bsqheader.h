#ifndef BSQHEADER
# define BSQHEADER

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

# define MAX_BUF 1024

char	*getcontents(int rowindex);
int		rowlen(int	rowindex);
int		collen(void);

#endif
