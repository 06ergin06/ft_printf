#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int n = 42;
	int *ptr = &n;
	ft_printf("%d",ft_printf(" merhaba %c %s %d %%  %p ", 'a', "dosakodksao", 1234, ptr));
}