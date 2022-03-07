/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:39:02 by mattif            #+#    #+#             */
/*   Updated: 2022/03/03 02:24:03 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	fmsg(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	bta(int signum, siginfo_t *info, void *context)
{
	static int	g_pid = 0;
	static char	c = 0xFF;
	static int	bit = 0;	

	(void) context;
	if (g_pid != info->si_pid)
	{
		c = 0xFF;
		bit = 0;
		g_pid = info->si_pid;
	}
	if (signum == 30)
		c |= 0x80 >> bit;
	else if (signum == 31)
		c ^= 0x80 >> bit;
	if (bit++ == 8)
	{
		if (!c)
			fmsg(g_pid, 30);
		ft_putchar(c);
		bit = 0;
		c = 0xFF;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 1 || av[1] != NULL)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	sa.sa_sigaction = bta;
	sa.sa_flags = SA_SIGINFO;
	sigaction(30, &sa, NULL);
	sigaction(31, &sa, NULL);
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
