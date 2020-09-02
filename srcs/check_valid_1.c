/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:19:02 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/02 18:03:50 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		firstrow_valid(void)
{
	if (get_rowlen(1) < 4)
	{
		write(1, FIRST_ROW_ERR_MSG, sizeof(FIRST_ROW_ERR_MSG));
		return (0);
	}
	return (1);
}

int		symbol_valid(char *symbol)
{
	int	i;

	if (symbol[0] == symbol[1] ||
	symbol[0] == symbol[2] || symbol[1] ==symbol[2])
	{
		write(1, SYMBOL_SAME_MSG, sizeof(SYMBOL_SAME_MSG));
		return (0);
	}
	i = 0;
	while (i < 3)
	{
		if (!((symbol[i] >= 9 && symbol[i] <= 13)
		|| (symbol[i] >= 32 && symbol[i] <= 126)))
		{
			write(1, SYMBOL_WRONG_MSG, sizeof(SYMBOL_WRONG_MSG));
			return (0);
		}
		i++;
	}
	return (1);
}

int		box_valid(char **grid_map, int collen)
{
	int	i;
	int	rowlen;

	rowlen = get_rowlen(2);
	if (rowlen < 1)
	{
		write(1, ROW_SHORT_MSG, sizeof(ROW_SHORT_MSG));
		return (0);
	}
	i = 1;
	while (i < collen)
	{
		if (grid_map[i][0] == '\0')
		{
			write(1, COL_DIFF_MSG, sizeof(COL_DIFF_MSG));
			return(0);
		}
		if (grid_map[i][rowlen] != '\n')
		{
			write(1, ROW_DIFF_MSG, sizeof(ROW_DIFF_MSG));
			return(0);
		}
		++i;
	}
	return (1);
}

int		map_valid(char **grid_map, char *symbol, int collen)
{
	int		col;
	int		row;
	int		rowlen;

	rowlen = get_rowlen(2);
	col = 0;
	while (col < collen)
	{
		row = 0;
		while (row < rowlen)
		{
			if (grid_map[col][row] != symbol[0]
			&& grid_map[col][row] != symbol[1])
			{
				write(1, WRONG_CHAR_MSG, sizeof(WRONG_CHAR_MSG));
				return (0);
			}
			row++;
		}
		col++;
	}
	return (1);
}

int		collen_valid(int collen)
{
	if (collen < 1)
	{
		write(1, COL_SHORT_MSG, sizeof(COL_SHORT_MSG));
		return (0);
	}
	return (1);
}
