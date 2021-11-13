/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:47:58 by byuri             #+#    #+#             */
/*   Updated: 2021/07/31 17:48:08 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send(pid_t pid, char c)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (c & i)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit_error("Signal error\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_error("Signal error\n");
		}
		usleep(130);
		i /= 2;
	}
	return (0);
}

static void	ft_isdigit(char *c)
{
	if (c)
	{
		if (*c == '-')
			c++;
		while (*c)
		{
			if (*c > '9' || *c < '0')
				exit_error("ERROR: INVALID PID");
			c++;
		}	
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*mssg;
	int		i;

	if (argc != 3)
		exit_error("wrong arguments");
	ft_isdigit(argv[1]);
	pid = ft_atoi(argv[1]);
	mssg = argv[2];
	i = 0;
	while (mssg[i] != '\0')
		send(pid, mssg[i++]);
	send(pid, '\0');
	return (0);
}
