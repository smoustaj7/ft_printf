/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoustaj <smoustaj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:36:02 by smoustaj          #+#    #+#             */
/*   Updated: 2025/10/28 18:27:20 by smoustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	l(int nb)
{
	long	n;
	int		l;

	n = nb;
	l = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

int	ft_putnbr(int n)
{
	long	nb;
	char	c;
	int		len;

	nb = n;
	len = l(nb);
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write (1, &c, 1);
	return (len);
}
