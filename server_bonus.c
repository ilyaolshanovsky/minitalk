/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:51:22 by byuri             #+#    #+#             */
/*   Updated: 2021/07/31 17:51:31 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_signal(int sig, siginfo_t *info, void *ucontext)
{
	static int	ch;
	static int	counter;

	(void)ucontext;
	if (!counter)
		counter = 128;
	if (sig == SIGUSR1)
		ch += counter;
	counter /= 2;
	if (counter == 0)
	{
		if (ch == '\0')
		{
			if (info->si_pid != 0)
			{
				if (kill(info->si_pid, SIGUSR1) == -1)
					exit_error("Error");
			}
			ft_putchar_fd('\n', 1);
		}
		ft_putchar_fd((char)ch, 1);
		counter = 128;
		ch = 0;
	}	
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	(void)argv;
	pid = getpid();
	if (argc != 1)
		exit_error("wrong arguments");
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit_error("Wrong value");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit_error("Wrong value");
	while (1)
		pause();
	return (0);
}
