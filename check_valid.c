#include "bsqheader.h"

char g_filename[] = "test.txt";

// 심볼누락판단.
// 심볼중복판다.
// 심볼 출력 불가 문자 판단.
// 글로벌 변수 이름을 아직 안정했기에... 일단 나중에 확인. g_filename으로 정함 임의로.
int	symbolvalid(char *symbol)
{
	int	i;
	printf("%d", rowlen(1));
	if (rowlen(1) < 4) // 심볼투락판단.
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
	return (1);
}

int	boxvalid()
{
	int	i;
	int	temp;

	i = 2;
	// collen < 1 이면 not
	if (collen() < 1) // 나중에 확인.
		return (0);
	// rowlen < 1 이면 not
	else if (rowlen(1) < 1)
		return (0);
	// 끝 줄까지 반복해서 rowlen 체크 해서 길이 틀리면 not valid
	temp = rowlen(i++);
	while (i <= collen())
	{
		if (rowlen(i) != temp)
			return(0);
		i++;
	}
	return (1);
}

int	mapvalid(char *symbol)
{
	int		i;
	int		j;
	char	*contents;

	i = 2;
	while (i <= collen())
	{
		j = 0;
		contents = getcontents(i);
		while (contents[j] != '\0')
		{
			if (symbol[0] != contents[j] && symbol[1] != contents[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	isvalid_map(char *symbol)
{
	if (symbolvalid(symbol) && boxvalid() && mapvalid(symbol))
		return (1);
	return (0);
}

int main()
{
	char symbol[3] = "o.x";

	printf("\n%d", isvalid_map(symbol));
	return 0;
}