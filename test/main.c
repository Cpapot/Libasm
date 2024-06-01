#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/libasm.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_strlen_test(void);
void	ft_strcpy_test(void);
void	ft_strcmp_test(void);
void	ft_write_test(int test_file_fd);
void	ft_read_test(int test_file_fd);

int		main(int argc, char **argv)
{
	remove("testfile.txt");

	if (argc == 1 || !strcmp("ft_strlen", argv[1]))
		ft_strlen_test();
	if (argc == 1 || !strcmp("ft_strcpy", argv[1]))
		ft_strcpy_test();
	if (argc == 1 || !strcmp("ft_strcmp", argv[1]))
		ft_strcmp_test();
	if (argc == 1 || !strcmp("ft_write", argv[1]))
	{
		int test_fd = open("testfile.txt", O_WRONLY | O_CREAT | O_APPEND,  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		ft_write_test(test_fd);
		close(test_fd);
	}
	if (argc == 1 || !strcmp("ft_read", argv[1]))
	{
		errno = 0;
		int test_fd = open("testfile.txt", O_RDONLY | O_APPEND);
		ft_read_test(test_fd);
		close(test_fd);
	}

}
