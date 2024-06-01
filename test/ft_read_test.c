#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "../inc/libasm.h"

char	*is_read_test_valid(size_t ft_read_res, int ft_read_errno, size_t read_res, int read_errno, char *readBUFF, char *ft_readBUFF)
{
	if (ft_read_errno == read_errno && ft_read_res == read_res && !strcmp(readBUFF, ft_readBUFF))
		return("✅");
	else
		return("❌");
}

void	ft_read_unit_test(int fd)
{
	size_t	ft_read_res;
	int		ft_read_errno;
	size_t	read_res;
	int		read_errno;
	char	readBUFF[BUFFSIZE];
	char	ft_readBUFF[BUFFSIZE];

	errno = 0;
	read_res = read(fd, readBUFF, sizeof(readBUFF));
	read_errno = errno;
	read(fd, "\n", 1);
	errno = 0;
	ft_read_res = ft_read(fd, ft_readBUFF, sizeof(ft_readBUFF));
	ft_read_errno = errno;
	read(fd, "\n", 1);
	printf("%s : ft_read(len: %ld, errno: %d), read(len: %ld, errno: %d) \n",	\
			 is_read_test_valid(ft_read_res, ft_read_errno, read_res, read_errno, readBUFF, ft_readBUFF), \
			 ft_read_res, ft_read_errno, read_res, read_errno);
}

void	ft_read_test(int test_file_fd)
{
	printf("\n		ft_read tests:		\n");

	ft_read_unit_test(test_file_fd);

	ft_read_unit_test(95);

	printf("\n");
}
