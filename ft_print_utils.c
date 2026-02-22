/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:51:43 by iergin            #+#    #+#             */
/*   Updated: 2026/02/22 09:47:11 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_str(char *str)
{
	int	count;

	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (count);
}

int	ft_print_nbr(long n)
{
	int	count;

	count = ft_num_len(n);
	ft_putnbr_fd(n, 1);
	return (count);
}

int	ft_print_uint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_uint(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	count++;
	return (count);
}

int	ft_print_ptr(void *p)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	ptr = (unsigned long)p;
	if (!ptr)
		return (ft_print_str("(nil)"));
	count += ft_print_str("0x");
	count += hex_to_ptr(ptr);
	return (count);
}
