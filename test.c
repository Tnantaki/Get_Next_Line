#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	ft_test(void)
{
	static int a;

	a++;
	return (a);
}
int	main(void)
{
	int fd;
	int i = 0;

	fd = open("fdfile.txt", O_RDONLY);
	printf("fd :%d\n", fd);
	if (fd == -1)
		return (-1);
	close (fd);
	fd = open("fdfile.txt", O_RDONLY);
	printf("fd :%d\n", fd);
	return (0);
}
