/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 07:18:46 by iergin            #+#    #+#             */
/*   Updated: 2026/02/22 14:09:58 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	detect_sign(char s, va_list *args, int *count)
{
	if (s == 'c')
		ft_putchar(va_arg(*args, int), count);
	else if (s == 's')
		(*count) += ft_print_str(va_arg(*args, char *));
	else if (s == 'd' || s == 'i')
		(*count) += ft_print_nbr(va_arg(*args, int));
	else if (s == 'u')
		(*count) += ft_print_uint(va_arg(*args, unsigned int));
	else if (s == '%')
		ft_putchar('%', count);
	else if (s == 'p')
		(*count) += ft_print_ptr(va_arg(*args, void *));
	else if (s == 'x')
		(*count) += ft_print_hex(va_arg(*args, unsigned int), 0);
	else if (s == 'X')
		(*count) += ft_print_hex(va_arg(*args, unsigned int), 1);
	else
	{
		ft_putchar('%', count);
		ft_putchar(s, count);
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, input);
	count = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
			detect_sign(input[++i], &args, &count);
		else
		{
			ft_putchar_fd(input[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
