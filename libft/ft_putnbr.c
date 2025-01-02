/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:21:26 by mohabid           #+#    #+#             */
/*   Updated: 2024/11/15 10:53:47 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_lower(long n, int base)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n < base)
		return (count + ft_putchar(hex[n]));
	count += ft_putnbr_lower(n / base, base);
	return (count + ft_putchar(hex[n % base]));
}

int	ft_putnbr_upper(long n, int base)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n < base)
		return (count + ft_putchar(hex[n]));
	count += ft_putnbr_upper(n / base, base);
	return (count + ft_putchar(hex[n % base]));
}

int	ft_putnbr_pointer(unsigned long n, unsigned int base)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr("0"));
	if (n < base)
		return (count + ft_putchar(hex[n]));
	count += ft_putnbr_pointer(n / base, base);
	return (count + ft_putchar(hex[n % base]));
}