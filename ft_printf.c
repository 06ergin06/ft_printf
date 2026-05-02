/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 07:18:46 by iergin            #+#    #+#             */
/*   Updated: 2026/05/02 17:23:56 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	detect_sign(char s, va_list *args, int *count)
{
	if (s == 'c')
		(*count) += ft_putchar(va_arg(*args, int));
	else if (s == 's')
		(*count) += ft_print_str(va_arg(*args, char *));
	else if (s == 'd' || s == 'i')
		(*count) += ft_print_nbr(va_arg(*args, int));
	else if (s == 'u')
		(*count) += ft_print_uint(va_arg(*args, unsigned int));
	else if (s == 'p')
		(*count) += ft_print_ptr(va_arg(*args, void *));
	else if (s == 'x')
		(*count) += ft_print_hex(va_arg(*args, unsigned int), 0);
	else if (s == 'X')
		(*count) += ft_print_hex(va_arg(*args, unsigned int), 1);
	else if (s == '%')
		(*count) += ft_putchar('%');
	else if (s == '\0')
		*count = -1;
	else
	{
		(*count) += ft_putchar('%');
		(*count) += ft_putchar(s);
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	if (!input)
		return (-1);
	va_start(args, input);
	count = 0;
	while (*input && count != -1)
	{
		if (*input == '%')
		{
			input++;
			while (*input == ' ')
				input++;
			detect_sign(*input, &args, &count);
		}
		else
			count += ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (count);
}
