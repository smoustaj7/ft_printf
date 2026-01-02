/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoustaj <smoustaj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:45:14 by smoustaj          #+#    #+#             */
/*   Updated: 2025/10/28 18:39:42 by smoustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	char	*strl;
	char	*stru;
	long	nb;
	int		count;

	count = 0;
	nb = n;
	stru = "0123456789ABCDEF";
	strl = "0123456789abcdef";
	if (nb >= 16)
		count = ft_puthex(nb / 16, uppercase);
	if (uppercase)
		write (1, &stru[nb % 16], 1);
	else
		write (1, &strl[nb % 16], 1);
	count++;
	return (count);
}
