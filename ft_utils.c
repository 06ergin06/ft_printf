/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:51:40 by iergin            #+#    #+#             */
/*   Updated: 2026/02/22 10:07:34 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_num_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	hex_to_ptr(unsigned long n, int isBig)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n > 16)
	{
		if (isBig)
			count += hex_to_ptr((n / 16), 1);
		else
			count += hex_to_ptr((n / 16), 0);
	}
	if (isBig)
		ft_putchar_fd(ft_toupper(base[n % 16]), 1);
	else
		ft_putchar_fd((base[n % 16]), 1);
	count++;
	return (count);
}
