/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:19:04 by brmajor           #+#    #+#             */
/*   Updated: 2023/08/30 16:37:09 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	c;

	(void)context;
	c |= (signum == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		sa.sa_sigaction = &sig_handler;
		sa.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			error_handler("Failed to change SIGUSR1's behavior");
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			error_handler("Failed to change SIGUSR2's behavior");
	}
}
