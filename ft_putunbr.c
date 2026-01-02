/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoustaj <smoustaj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:48:15 by smoustaj          #+#    #+#             */
/*   Updated: 2025/10/28 18:57:36 by smoustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	l(unsigned int n)
{
	int		l;

	l = 0;
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

int	ft_putunbr(unsigned int n)
{
	char	c;
	int		len;

	len = l(n);
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (n >= 10)
		ft_putunbr(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
	return (len);
}
