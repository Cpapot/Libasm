#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/libasm.h"
# define BUFFSIZE 100000

char	*is_strlen_test_valid(size_t first, size_t second)
{
	if (first == second)
		return("✅");
	else
		return("❌");
}

void	ft_strlen_unit_test(char *str)
{
	size_t ft_strlen_res;
	size_t strlen_res;

	strlen_res = strlen(str);
	ft_strlen_res = ft_strlen(str);
	printf("%s : (ft_strlen: %ld, strlen: %ld) \n",	\
			 is_strlen_test_valid(ft_strlen_res, strlen_res), ft_strlen_res, strlen_res);
}

void	ft_strlen_test(void)
{
	char	testBUFF[BUFFSIZE];
	size_t	i;

	printf("\n		ft_strlen tests:		\n");
	i = 0;
	sprintf(testBUFF, "bonjour");
	ft_strlen_unit_test(testBUFF);
	sprintf(testBUFF, "string un plus longue");
	ft_strlen_unit_test(testBUFF);
	sprintf(testBUFF, " !\"#$%%&\\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~'");
	ft_strlen_unit_test(testBUFF);
	bzero(&testBUFF, sizeof(testBUFF));
	ft_strlen_unit_test(testBUFF);
	while (i != BUFFSIZE - 1)
	{
		testBUFF[i] = 'a';
		i++;
	}
	ft_strlen_unit_test(testBUFF);
	//cause memory leak but work
	//testBUFF[i] = 'a';
	//ft_strlen_unit_test(testBUFF);
	printf("\n");
}
