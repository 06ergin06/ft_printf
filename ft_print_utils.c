/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:51:43 by iergin            #+#    #+#             */
/*   Updated: 2026/02/22 08:57:09 by iergin           ###   ########.fr       */
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
	int count;
	count = ft_num_len(n);
	ft_putnbr_fd(n, 1);

	return (count);
}
