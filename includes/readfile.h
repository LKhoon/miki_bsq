#ifndef READFILE_H
# define READFILE_H

void	read_iter(int fd, int alreadyread);
int		lenfor_nextenter(int alreadyread);
int		howmany_charbefore(int rowindex);
int		get_rowlen(int rowindex);
char	*get_info(int row_1_len);
int		is_number(char c);
int		get_collen(char *info_contents);
void	getsymbol(char *symbol, char *info_contents);

#endif
