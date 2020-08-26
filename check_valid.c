#include "bsqheader.h"

int	find_line_end()
{
	int		fd;
	int		count;
	int		result;
	int		temp;
	char	buf[MAX_BUF];

	result = 0;
	fd = open(g_filename, O_RDONLY);
	while ((temp = read(fd, buf, sizeof(buf))) > 0)
	{
		count = 0;
		while (buf[count] != '\n' && count < temp)
		{
			count++;
			result++;
		}
		if (buf[count] == '\n')
			return (result);
	}
	
	return (0);
}
// 심볼누락판단.
// 심볼중복판다.
// 심볼 출력 불가 문자 판단.
// 글로벌 변수 이름을 아직 안정했기에... 일단 나중에 확인. g_filename으로 정함 임의로.
int	symbolvalid(char *symbol)
{
	int	i;

	if (find_line_end() < 4) // 심볼투락판단.
		return (0);
	if (symbol[0] == symbol[1]) // 심볼중복판단.
		return (0);
	else if (symbol[0] == symbol[2])
		return (0);
	else if (symbol[1] == symbol[2])
		return (0);
	i = 0;
	while (symbol[i])
	{
		if (symbol[i] < ' ' || symbol[i] > '~') // 심볼 출력불가문자 판단.
			return (0);
		i++;
	}
}

// collen < 1 이면 not valid
// rowlen < 1 이면 not valid
// 끝 줄까지 반복해서 rowlen 체크 해서 길이 틀리면 not valid
int	boxvalid()
{
	// collen < 1 이면 not
	if (collen() < 1)
		return (0);
	// rowlen < 1 이면 not
	else if (rowlen(1) < 1)
		return (0);
	// rowlen 체크해서
}

int	mapvalid(char *symbol)
{
	int	i;
	int	j;
	int	fd;
	int	temp;
	char buf[MAX_BUF];

	j = 0;
	i = 0;
	temp = find_line_end() + 1;
	fd = open(g_filename, O_RDONLY);
	read(fd, buf, temp);
	while (read(fd, buf, sizeof(buf)) > 0)
	{
		while ( )
	}
}

int	isvalid_map()
{

}

// int main()
// {
// 	printf("%d", find_line_end());
// }