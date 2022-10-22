#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*dst;
// 	size_t	lens1;
// 	size_t	lens2;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	lens1 = strlen(s1);
// 	lens2 = strlen(s2);
// 	dst = malloc(sizeof(char) * (lens1 + lens2 + 1));
// 	if (!dst)
// 		return (NULL);
// 	while (lens1--)
// 		dst[i++] = s1[j++];
// 	j = 0;
// 	while (lens2--)
// 		dst[i++] = s2[j++];
// 	dst[i] = '\0';
// 	free(s1);
// 	free(s2);
// 	return (dst);
// }
/*
int	main(void)
{
	char *str1 = strdup("Mallo");
	char *str2 = strdup("Hello");
	char *ptr = "Hello";

	ptr = ft_strjoin(str1, str2 + 2);
	printf("%s", ptr);
	free (ptr);

}
*/
