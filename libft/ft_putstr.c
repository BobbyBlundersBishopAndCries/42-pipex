/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:12:12 by mohabid           #+#    #+#             */
/*   Updated: 2024/11/14 14:52:37 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	count;

	if (s == NULL)
		return (ft_putstr("(null)"));
	count = 0;
	while (*s)
	{
		count += ft_putchar(*s++);
	}
	return (count);
}
