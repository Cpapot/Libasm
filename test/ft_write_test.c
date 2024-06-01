#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "../inc/libasm.h"

char	*is_write_test_valid(size_t ft_write_res, int ft_write_errno, size_t write_res, int write_errno)
{
	if (ft_write_errno == write_errno && ft_write_res == write_res)
		return("✅");
	else
		return("❌");
}

void	ft_write_unit_test(char *str, int fd, ssize_t len)
{
	size_t	ft_write_res;
	int		ft_write_errno;
	size_t	write_res;
	int		write_errno;

	errno = 0;
	write_res = write(fd, str, len);
	write_errno = errno;
	write(fd, "\n", 1);
	errno = 0;
	ft_write_res = ft_write(fd, str, len);
	ft_write_errno = errno;
	write(fd, "\n", 1);
	printf("%s : ft_write(len: %ld, errno: %d), write(len: %ld, errno: %d) \n",	\
			 is_write_test_valid(ft_write_res, ft_write_errno, write_res, write_errno), \
			 ft_write_res, ft_write_errno, write_res, write_errno);
}

void	ft_write_test(int test_file_fd)
{
	char	testBUFF[BUFFSIZE];

	printf("\n		ft_write tests:		\n");

	sprintf(testBUFF, " !\"#$%%&\\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~'");
	ft_write_unit_test(testBUFF, test_file_fd, strlen(testBUFF));


	testBUFF[0] = 0;
	ft_write_unit_test(testBUFF, test_file_fd, strlen(testBUFF));

	sprintf(testBUFF, "testoui\n\n\n");
	ft_write_unit_test(testBUFF, test_file_fd, strlen(testBUFF));

	ft_write_unit_test(NULL, 85, 0);
	ft_write_unit_test(NULL, -1, 0);
	printf("\n");
}
