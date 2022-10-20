#include <stdio.h>
int	ft_add(int s)
{
	static char a[50];

	// i = 0;
	for	(int i=0;i<51;i++)
	{
		printf("%c, ", a[i] + s);
	}
	// i += s;
	return (0);
}
/*
int	main(void)
{
	int s = 48;
	// printf("%d\n", ft_add(s));
	ft_add(s);
	// printf("%d\n", ft_add(s));
	// printf("%c\n", ft_add(s));
	// printf("%c\n", ft_add(s));
	// printf("%c\n", ft_add(s));
	// char str[10];
	// for (int i=0;i<10;i++)
	// 	printf("%c, ", str[i]);
	// printf("\n");
}
*/
