#ifndef COMMON_H
# define COMMON_H

# define MAX_BUF 1024
# define NO_ARG_MSG "\n *** PLEASE TYPE THE MAP DATA ***\n (when you want finish typing, press '[Ctrl] + [D]')\n :"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "bsq.h"
#include "printer.h"
#include "readfile.h"
#include "check_valid.h"

extern char	*g_filename;

#endif
