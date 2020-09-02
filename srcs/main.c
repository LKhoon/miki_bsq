/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:18:20 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/02 18:15:32 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*g_filename;

void	get_mapdata(void)
{
	int		fd;
	int		read_count;
	char	buf[MAX_BUF];

	write(1, NO_ARG_MSG, sizeof(NO_ARG_MSG));
	fd = open("typed_map.data", O_RDWR | O_CREAT | O_TRUNC, 0755);
	while ((read_count = read(0, buf, sizeof(buf))) > 0)
		write(fd, buf, read_count);
	g_filename = "typed_map.data";
	close(fd);
}

void	run_program(char **grid_map, int **grid_bsq)
{
	char	*info_contents;
	int		collen;
	char	symbol[3];
	int		bslocation[2];

	info_contents = get_info(get_rowlen(1));
	collen = get_collen(info_contents);
	bslocation[0] = 0;
	bslocation[1] = 0;
	if (check_exception(grid_map, symbol) == 0)
		return ;
	getsymbol(symbol, info_contents);
	grid_map = init_grid_map(collen);
	grid_bsq = init_grid_bsq(collen + 1, get_rowlen(2) + 1);
	bsq(grid_bsq, grid_map, bslocation, collen, symbol);
	mark_square(grid_map, grid_bsq, symbol, bslocation);
	print_bsq(grid_map, collen);
	free(grid_bsq);
	free(grid_map);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	char	**grid_map;
	int		**grid_bsq;
	int		i;

	grid_map = NULL;
	grid_bsq = NULL;
	if (argc == 1)
	{
		get_mapdata();
		print_intro();
		run_program(grid_map, grid_bsq);
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			g_filename = argv[i];
			print_intro();
			if (check_filename() != 0)
				run_program(grid_map, grid_bsq);
			i++;
		}
	}
	return (0);
}
