#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int n = 42;
	int *ptr = &n;
	unsigned int x = 1;
	ft_printf("%d",ft_printf(" merhaba %c %s %d %%  %p %u %x %X ", 'a', "dosakodksao", 1234, ptr, x, n, n));
	printf("%d",printf("\nmerhaba %c %s %d %%  %p %u %x %X ", 'a', "dosakodksao", 1234, ptr, x, n, n));
}