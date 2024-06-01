#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/libasm.h"

char	*is_strcmp_test_valid(int first, int second)
{
	if ((first <= 0 && second <= 0) || (first >= 0 && second >= 0))
		return("✅");
	else
		return("❌");
}

void	ft_strcmp_unit_test(const char *s1, const char *s2)
{
	int ft_strcmp_res;
	int strcmp_res;

	strcmp_res = strcmp(s1, s2);
	ft_strcmp_res = ft_strcmp(s1, s2);
	printf("%s : (ft_strcmp: %d, strcmp: %d) \n",	\
			 is_strcmp_test_valid(ft_strcmp_res, strcmp_res), ft_strcmp_res, strcmp_res);
}

void	ft_strcmp_test(void)
{
	char	testBUFF[BUFFSIZE];
	char	testBUFF1[BUFFSIZE];
	size_t	i;

	printf("\n		ft_strcmp tests:		\n");
	i = 0;
	sprintf(testBUFF, "1234567");
	sprintf(testBUFF1, "1234568");
	ft_strcmp_unit_test(testBUFF, testBUFF1);
	sprintf(testBUFF, "string un plus longue");
	ft_strcmp_unit_test(testBUFF, testBUFF1);
	sprintf(testBUFF, " !\"#$%%&\\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~'");
	sprintf(testBUFF1, " !\"#$%%&\\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~'");
	ft_strcmp_unit_test(testBUFF, testBUFF1);
	bzero(&testBUFF, sizeof(testBUFF));
	bzero(&testBUFF1, sizeof(testBUFF1));
	ft_strcmp_unit_test(testBUFF, testBUFF1);
	while (i != BUFFSIZE - 1)
	{
		testBUFF[i] = 'a';
		testBUFF1[i] = 'a';
		i++;
	}
	//testBUFF1[i - 1] = 'b';
	ft_strcmp_unit_test(testBUFF, testBUFF1);
	bzero(&testBUFF, sizeof(testBUFF));
	bzero(&testBUFF1, sizeof(testBUFF1));
	testBUFF1[0] = 'a';
	ft_strcmp_unit_test(testBUFF, testBUFF1);
	printf("\n");
}
