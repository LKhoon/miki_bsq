#ifndef CHECK_VALID_H
# define CHECK_VALID_H

# define WRONG_FILE_MSG "*** You typed filename doesn't exist : "
# define FIRST_ROW_ERR_MSG "*** INFO DATA is not valid :( ***\n"
# define SYMBOL_SAME_MSG "*** SYMBOLS have overlap :( ***\n"
# define SYMBOL_WRONG_MSG "*** SYMBOLS have unprintable charactor :( ***\n"
# define ROW_SHORT_MSG "*** ROW LENGTH is too short :( *** \n"
# define COL_DIFF_MSG "*** Given COLLUM LENGTH is Wrong :( ***\n"
# define ROW_DIFF_MSG "*** ROW LENGTH is not constant :( ***\n"
# define WRONG_CHAR_MSG "*** This map have a WRONG CHAR :( ***\n"
# define COL_SHORT_MSG "*** COLLUM LENGTH is too short :( ***\n"

int		firstrow_valid(void);
int		symbol_valid(char *symbol);
int		box_valid(char **grid_map, int collen);
int		map_valid(char **grid_map, char *symbol, int collen);
int		collen_valid(int collen);
int		check_filename();
int		check_exception(char **grid_map, char *symbol);

#endif
