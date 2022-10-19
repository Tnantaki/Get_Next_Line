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
	char *str;
	int fd;
	int i = 0;

	fd = open("fdfile.txt", O_RDONLY);
	printf("fd :%d\n", fd);
	if (fd == -1)
		return (-1);
	read(fd,
	printf("get 1:%s\n", str);
	read(fd, str, 5);
	printf("get 2:%s\n", str);
	// printf("fd :%d\n", fd);
	return (0);
}
