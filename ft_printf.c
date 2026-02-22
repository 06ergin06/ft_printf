/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 07:18:46 by iergin            #+#    #+#             */
/*   Updated: 2026/02/22 09:11:53 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	detect_sign(char s, va_list *args, int *count)
{
	if (s == 'c' && (*count)++)
		ft_putchar_fd(va_arg(*args, int), 1);
	else if (s == 's')
		(*count) += ft_print_str(va_arg(*args, char *));
	else if (s == 'd' || s == 'i')
		(*count) += ft_print_nbr(va_arg(*args, int));
	else if (s == '%' && (*count)++)
		ft_putchar_fd('%', 1);
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
		{
			i++;
			detect_sign(input[i], &args, &count);
		}
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
