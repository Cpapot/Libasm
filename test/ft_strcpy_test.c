#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/libasm.h"

char	*is_strcpy_test_valid(char *ft_strcpy_res, char *strcpy_res, char *ft_strcpy_dest, char *strcpy_dest)
{
	if (!strcmp(ft_strcpy_res, strcpy_res) && !strcmp(ft_strcpy_dest, strcpy_dest))
		return("✅");
	else
	{
		if (strcmp(ft_strcpy_res, strcpy_res))
			printf("ft_strcpy_res: \"%s\",\n strcpy_res: \"%s\"\n", ft_strcpy_res, strcpy_res);
		if (strcmp(ft_strcpy_dest, strcpy_dest))
			printf("ft_strcpy_dest: \"%s\",\n strcpy_dest: \"%s\"\n", ft_strcpy_dest, strcpy_dest);
		return("❌");
	}
}

void	ft_strcpy_unit_test(char *str)
{
	char *ft_strcpy_res;
	char *strcpy_res;
	char ft_strcpy_dest[BUFFSIZE];
	char strcpy_dest[BUFFSIZE];

	bzero(&ft_strcpy_dest, sizeof(ft_strcpy_dest));
	bzero(&strcpy_dest, sizeof(strcpy_dest));
	strcpy_res = strcpy(strcpy_dest, str);
	ft_strcpy_res = ft_strcpy(ft_strcpy_dest, str);
	//printf("%s", strcpy_dest);
	if (strlen(str) >= 100)
		printf("%s : too long to print \n",	\
				 is_strcpy_test_valid(ft_strcpy_res, strcpy_res, ft_strcpy_dest, strcpy_dest));
	else
		printf("%s : \"%s\" \n",	\
				 is_strcpy_test_valid(ft_strcpy_res, strcpy_res, ft_strcpy_dest, strcpy_dest), str);

}

void	ft_strcpy_test(void)
{
	char	testBUFF[BUFFSIZE];
	size_t	i;

	i = 0;
	printf("\n		ft_strcpy tests:		\n");
	sprintf(testBUFF, "bonjour");
	ft_strcpy_unit_test(testBUFF);
	sprintf(testBUFF, "string un plus longue");
	ft_strcpy_unit_test(testBUFF);
	sprintf(testBUFF, " !\"#$%%&\\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~'");
	ft_strcpy_unit_test(testBUFF);
	bzero(&testBUFF, sizeof(testBUFF));
	ft_strcpy_unit_test(testBUFF);
	while (i != BUFFSIZE - 1)
	{
		testBUFF[i] = 'a';
		i++;
	}
	ft_strcpy_unit_test(testBUFF);
	//cause memory leak but work
	//testBUFF[i] = 'a';
	//ft_strcpy_unit_test(testBUFF);
	printf("\n");
}
