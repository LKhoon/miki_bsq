#include "common.h"
#include "readfile.h"
#include "bsq.h"
#include "printer.h"

char  *g_filename;

int		main(int argc, char** argv)
{
	char **grid_map;
	int **grid_bsq;
	char symbol[3];
	int bslocation[2];
	bslocation[0] = 0;
	bslocation[1] = 0;
	int col;
	char *info_contents;
	int fd;
	char buf[MAX_BUF];
	int read_count;
	int i;

	if (argc == 1)
	{
		write(1, "no argv\0", 20);
		fd = open("temp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
		read_count = read(0, buf, sizeof(buf));
		write(fd, buf, read_count);
		close(fd);
	}
	else
	{
		i = 1;
		while(argv[i])
		{
			g_filename = argv[i];
			info_contents = get_info(get_rowlen(1));
			col = get_collen(info_contents);

			getsymbol(symbol, info_contents);
			grid_map = init_grid_map(get_collen(info_contents));
			grid_bsq = init_grid_bsq(get_collen(info_contents) + 1, get_rowlen(2) + 1);

			bsq(grid_bsq, grid_map, bslocation, col, symbol);
			mark_square(grid_map, grid_bsq, symbol, bslocation);
			print_bsq(grid_map, col);
			free(grid_bsq);
			free(grid_map);
			write(1, "\n", 2);
			i++;
		}
	}
	return (0);
}
