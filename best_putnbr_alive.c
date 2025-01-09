/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_putnbr_alive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 06:25:05 by mohabid           #+#    #+#             */
/*   Updated: 2025/01/09 15:09:50 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	char	buffer[12];
	int		i;
	int		is_negative;

	i = 10;
	buffer[11] = '\0';
	if (n == 0)
		buffer[i--] = '0';
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n = n / 10;
	}
	if (is_negative)
		buffer[i--] = '-';
	write(STDOUT_FILENO, &buffer[i + 1], 11 - i);
}

int	main(void)
{
	int	a;

	a = -2143;
	putnbr(a);
	write(STDOUT_FILENO, "\n", 1);
}
