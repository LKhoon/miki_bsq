/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:16:57 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/09/02 18:16:59 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	read_iter(int fd, int alreadyread)
{
	char *buf[MAX_BUF];

	while (alreadyread > 1024)
	{
		read(fd, buf, 1024);
		alreadyread -= 1024;
	}
	read(fd, buf, alreadyread);
}

int		lenfor_nextenter(int alreadyread)
{
	int		fd;
	int		count;
	int		result;
	int		temp;
	char	buf[MAX_BUF];

	result = 0;
	fd = open(g_filename, O_RDONLY);
	read_iter(fd, alreadyread);
	while ((temp = read(fd, buf, sizeof(buf))) > 0)
	{
		count = 0;
		while (buf[count] != '\n' && count < temp)
		{
			count++;
			result++;
		}
		if (buf[count] == '\n')
		{
			close(fd);
			return (result + 1);
		}
	}
	close(fd);
	return (-1);
}

int		howmany_charbefore(int rowindex)
{
	int		i;
	int		alreadyread;

	i = 1;
	alreadyread = 0;
	while (i < rowindex)
	{
		alreadyread += lenfor_nextenter(alreadyread);
		if (lenfor_nextenter(alreadyread) == -1)
			return (-1);
		++i;
	}
	return (alreadyread);
}

int		get_rowlen(int rowindex)
{
	int	readstart;

	readstart = howmany_charbefore(rowindex);
	return (lenfor_nextenter(readstart) - 1);
}

char	*get_info(int row_1_len)
{
	char	*contents;
	int		fd;

	contents = (char*)malloc(sizeof(char) * row_1_len + 1);
	fd = open(g_filename, O_RDONLY);
	read(fd, contents, row_1_len);
	contents[row_1_len] = '\0';
	close(fd);
	return (contents);
}
