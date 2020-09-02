/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:16:51 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/02 21:05:16 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


int		get_collen(char *info_contents)
{
	int		start;
	int		end;
	int		num;

	start = 0;
	end = 0;
	while (info_contents[end] != '\0')
		end++;
	end -= 4;
	num = 0;
	while (start <= end)
	{
		if (!is_number(info_contents[start]))
			return (-1);
		else
		{
			num = num * 10 + info_contents[start++] - '0';
		}
	}
	return (num);
}

void	getsymbol(char *symbol, char *info_contents)
{
	int		end;

	end = 0;
	while (info_contents[end] != '\0')
		end++;
	symbol[2] = info_contents[end - 1];
	symbol[1] = info_contents[end - 3];
	symbol[0] = info_contents[end - 2];
}
