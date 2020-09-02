/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:19:02 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/02 18:15:57 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		check_filename()
{
	int	fd;

	fd = open(g_filename, O_RDONLY);
	if (fd < 0)
	{
		write(1,WRONG_FILE_MSG, sizeof(WRONG_FILE_MSG));
		write(1, g_filename, sizeof(g_filename));
		write(1, " ***", 4);
		write(1, "\n\n", 2);
		return (0);
	}
	return (1);
}

int		check_exception(char **grid_map, char *symbol)
{
		char	*info_contents;
		int		collen;

		if (firstrow_valid() == 0)
			return (0);
		info_contents = get_info(get_rowlen(1));
		collen = get_collen(info_contents);
		getsymbol(symbol, info_contents);
		if (symbol_valid(symbol) == 0)
			return (0);
		if (collen_valid(collen) == 0)
			return (0);
		grid_map = init_grid_map(collen);
		if (box_valid(grid_map, collen) == 0)
			return (0);
		if (map_valid(grid_map, symbol, collen) == 0)
			return (0);
		return (1);
}
