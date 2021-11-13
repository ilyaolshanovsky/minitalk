/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:50:58 by byuri             #+#    #+#             */
/*   Updated: 2021/07/31 17:51:04 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int sig)
{
	static int	ch;
	static int	counter;

	if (!counter)
		counter = 128;
	if (sig == SIGUSR1)
		ch += counter;
	counter /= 2;
	if (counter == 0)
	{
		if (ch == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd((char)ch, 1);
		counter = 128;
		ch = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	pid = getpid();
	if (argc != 1)
		exit_error("wrong arguments");
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
	while (1)
		pause();
	return (0);
}
