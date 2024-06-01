#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/libasm.h"
#include <errno.h>

void	ft_strlen_test(void);
void	ft_strcpy_test(void);
void	ft_strcmp_test(void);

int		main(int argc, char **argv)
{
	if (argc == 1 || !strcmp("ft_strlen", argv[1]))
		ft_strlen_test();
	if (argc == 1 || !strcmp("ft_strcpy", argv[1]))
		ft_strcpy_test();
	if (argc == 1 || !strcmp("ft_strcmp", argv[1]))
		ft_strcmp_test();
	if (argc == 1 || !strcmp("ft_write", argv[1]))
	{
		ft_write(1, "test\n", 5);
		printf("errno: %s\n", strerror(errno));
	}
}
