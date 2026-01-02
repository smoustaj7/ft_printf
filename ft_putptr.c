/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoustaj <smoustaj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:28:31 by smoustaj          #+#    #+#             */
/*   Updated: 2025/10/30 13:21:14 by smoustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex_long(unsigned long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += put_hex_long(n / 16);
	write(1, &hex[n % 16], 1);
	return (count + 1);
}

int	ft_putptr(unsigned long p)
{
	int	count;

	count = 0;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (count + 5);
	}
	write (1, "0x", 2);
	count += 2;
	count += put_hex_long(p);
	return (count);
}
