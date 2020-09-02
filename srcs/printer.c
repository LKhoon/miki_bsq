/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:21:52 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/02 21:00:19 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_bsq(char **grid_map, int collen)
{
	int col;
	int rowlen;

	rowlen = get_rowlen(2);
	col = 0;
	while (col < collen)
	{
		write(1, grid_map[col], rowlen + 1);
		col++;
	}
}

void	print_intro(void)
{

	int name_len;

	name_len = 0;
	while (g_filename[name_len])
		name_len++;
	write(1, "---------------------------------------\n", 40);
	write(1, "*** THIS IS MAP OF : ", 21);
	write(1, g_filename, name_len);
	write(1, " ***\n", 5);
	write(1, "---------------------------------------\n", 40);
	write(1, "\n", 1);
}
