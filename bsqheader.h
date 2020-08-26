#ifndef BSQHEADER
# define BSQHEADER

# define MAX_BUF 1024

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	g_filename[] = "test.txt";

char	*getcontents(int rowindex);
int		rowlen(int	rowindex);
int		collne(void);


#endif
