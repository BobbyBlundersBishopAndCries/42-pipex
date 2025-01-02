/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:09:57 by mohabid           #+#    #+#             */
/*   Updated: 2024/11/15 17:53:54 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, s);
	if (!s || write(1, 0, 0) == -1)
		return (-1);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s != '\0')
				count += ft_print_format(*s++, ap);
			else
				break ;
		}
		else
			count += ft_putchar(*s++);
	}
	va_end(ap);
	return (count);
}
