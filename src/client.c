/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:20:10 by brmajor           #+#    #+#             */
/*   Updated: 2023/09/20 13:15:17 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	error_check(int ac, char **av)
{
	int		i;

	if (ac != 3)
		error_handler("Error: incorrect number of arguments");
	i = 0;
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
			error_handler("Error: incorrect PID");
		i++;
	}
	if (*av[2] == 0)
		error_handler("Error: empty message");
}

void	send_msg(pid_t serv_pid, char *msg)
{
	int		i;
	char	c;

	while (*msg)
	{
		i = 8;
		c = *msg++;
		while (i--)
		{
			if (c >> i & 1)
				kill(serv_pid, SIGUSR2);
			else
				kill(serv_pid, SIGUSR1);
			usleep(300);
		}
	}
	i = 8;
	while (i--)
	{
		kill(serv_pid, SIGUSR1);
		usleep(300);
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		write(1, "character delivered!\n", 22);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				serv_pid;

	error_check(ac, av);
	serv_pid = ft_atoi(av[1]);
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_handler("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler("Failed to change SIGUSR2's behavior");
	send_msg(serv_pid, av[2]);
}
