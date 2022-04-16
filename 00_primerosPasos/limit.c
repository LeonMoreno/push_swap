#include <stdio.h>
#include <limits.h>

int ft_long_atoi(char *str)
{
	long int	num;
	int			sing;

	num = 0;
	sing = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sing = -1;
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return 7;
		else	
			num = num * 10 + *str - '0';
		str++;
	}
	if (num < INT_MIN || num > INT_MAX)
		return 7;
	return (num * sing);
}

int main(void)
{
	char *str = "-87";

	printf("Num = %d\n", ft_long_atoi(str));
	printf("Num = %d\n", ft_long_atoi("+34d56"));
	printf("Num = %d\n", ft_long_atoi("2147483648"));
	return (0);
}
