#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int n = 42;
	int *ptr = &n;
	unsigned int x = 42;
	ft_printf("%d",ft_printf(" merhaba %c %s %d %%  %p %u ", 'a', "dosakodksao", 1234, ptr, x));
	printf("%d",printf("\nmerhaba %c %s %d %%  %p %u ", 'a', "dosakodksao", 1234, ptr, x));

}