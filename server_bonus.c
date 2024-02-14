/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:08 by abel-baz          #+#    #+#             */
/*   Updated: 2024/01/25 12:14:21 by abel-baz         ###   ########.fr       */
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

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static int	acc;

	(void)context;
	if (signum == SIGUSR1)
	{
		acc |= (0b00000001 << bit);
		bit++;
	}
	else if (signum == SIGUSR2)
		bit++;
	if (bit == 8)
	{
		if (acc == 0)
			kill(info->si_pid, SIGUSR2);
		ft_putchar(acc);
		bit = 0;
		acc = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = ft_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
