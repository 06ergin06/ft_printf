/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 07:18:21 by iergin            #+#    #+#             */
/*   Updated: 2026/02/22 09:21:03 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *input, ...);
int	ft_print_str(char *str);
int	ft_print_nbr(long n);
int	ft_num_len(long n);
int hex_to_ptr(unsigned long n);
int	ft_print_ptr(void *p);

#endif