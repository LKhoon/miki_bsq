#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char g_filename[] = "test.txt";

int rowlen(int fd, int last)
{
    int     count;
    int     result;
    int     temp;
    char    buf[1024];
    result = 0;
    while ((temp = read(fd, buf, sizeof(buf))) > 0)
    {
        count = 0;
        while (buf[count] != '\n' && count < temp)
        {
            count++;
            result++;
        }
		if (result == last)
			continue ;
        if (buf[count] == '\n')
            return (result);
    }
    return (-1);
}

int main(void)
{
    int fd;
	int	test;

    fd = open(g_filename, O_RDONLY);
	test = rowlen(fd, 0);
    printf("%d", test);
	test = rowlen(fd, test);
    printf("%d", test);
	test = rowlen(fd, test);
    printf("%d", test);
    return (0);
}
