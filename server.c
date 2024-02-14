/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:08 by abel-baz          #+#    #+#             */
/*   Updated: 2024/01/24 18:20:38 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_handler(int signum)
{
	static int	bit;
	static int	acc;

	if (signum == SIGUSR1)
	{
		acc |= (0b00000001 << bit);
		bit++;
	}
	else if (signum == SIGUSR2)
		bit++;
	if (bit == 8)
	{
		ft_putchar(acc);
		bit = 0;
		acc = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
