/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 07:18:46 by iergin            #+#    #+#             */
/*   Updated: 2026/02/22 08:23:53 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	detect_sign(char s, va_list args)
{
	if(s == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (s == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (s == 'd' || s == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (s == '%')
		ft_putchar_fd('%', 1);
}
int	ft_printf(const char *input, ...)
{
	va_list	args;
	int	i;

	va_start(args, input);
	i = 0;
	while (input[i]) {
		if (input[i] == '%')
		{
			if(input[i + 1])
			{
				detect_sign(input[i + 1], args);
				i++;
			}
		}
		else {
			ft_putchar_fd(input[i], 1);
		}
		i++;
	}

	va_end(args);
	return (0);
}
