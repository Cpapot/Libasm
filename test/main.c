#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/libasm.h"

void	ft_strlen_test(void);
void	ft_strcpy_test(void);

int		main(int argc, char **argv)
{
	if (argc == 1 || !strcmp("ft_strlen", argv[1]))
		ft_strlen_test();
	if (argc == 1 || !strcmp("ft_strcpy", argv[1]))
		ft_strcpy_test();
}
