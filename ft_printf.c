/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoustaj <smoustaj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:05:48 by smoustaj          #+#    #+#             */
/*   Updated: 2025/10/31 10:35:08 by smoustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	edge_case(const char *format, int i, int count)
{
	if (format[i] == '%')
	{
		write (1, "%", 1);
		return (count + 1);
	}
	else if (format[i])
	{
		write(1, "%", 1);
		ft_putchar(format[i]);
		return (count + 2);
	}
	return (count);
}

static int	t_data(const char *format, int i, va_list *args)
{	
	int	count;

	count = 0;
	if (format[i] == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (format[i] == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (format[i] == 'u')
		count += ft_putunbr(va_arg(*args, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		count += ft_puthex(va_arg(*args, unsigned int), (format[i] == 'X'));
	else if (format[i] == 'p')
		count += ft_putptr((unsigned long)(va_arg(*args, void *)));
	else
	{
		count += edge_case(format, i, count);
	}
	return (count);
}

static int	printing(const char *format, int d, int count)
{
	while (format[d])
	{
		count += ft_putchar(format[d++]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			count += t_data(format, ++i, &args);
		else if (format[i] == '%' && !format[i + 1])
			return (count + printing(format, i, count));
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
