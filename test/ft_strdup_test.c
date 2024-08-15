#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/libasm.h"

char	*is_strdup_test_valid(char *ft_strdup_res, char *strdup_res)
{
	if (!strcmp(ft_strdup_res, strdup_res))
		return("✅");
	else
	{
		printf("ft_strdup_res: \"%s\",\n strdup_res: \"%s\"\n", ft_strdup_res, strdup_res);
		return("❌");
	}
}

void	ft_strdup_unit_test(char *str)
{
	char *ft_strdup_res;
	char *strdup_res;

	strdup_res = strdup(str);
	ft_strdup_res = ft_strdup(str);
	//printf("%s", strdup_dest);
	if (strlen(str) >= 100)
		printf("%s : too long to print \n",	\
				 is_strdup_test_valid(ft_strdup_res, strdup_res));
	else
		printf("%s : \"%s\" \n",	\
				 is_strdup_test_valid(ft_strdup_res, strdup_res), str);
	if (ft_strdup_res)
		free(ft_strdup_res);
	if (strdup_res)
		free(strdup_res);
}

void	ft_strdup_test(void)
{
	char	testBUFF[BUFFSIZE];
	size_t	i;

	i = 0;
	printf("\n		ft_strdup tests:		\n");
	sprintf(testBUFF, "bonjour");
	ft_strdup_unit_test(testBUFF);
	sprintf(testBUFF, "string un plus longue");
	ft_strdup_unit_test(testBUFF);
	sprintf(testBUFF, " !\"#$%%&\\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~'");
	ft_strdup_unit_test(testBUFF);
	bzero(&testBUFF, sizeof(testBUFF));
	ft_strdup_unit_test(testBUFF);
	while (i != BUFFSIZE - 1)
	{
		testBUFF[i] = 'a';
		i++;
	}
	ft_strdup_unit_test(testBUFF);
	printf("\n");
}
