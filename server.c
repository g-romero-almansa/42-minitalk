/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:53:18 by gromero-          #+#    #+#             */
/*   Updated: 2022/06/21 12:11:47 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	action(int num_server, siginfo_t *inf, void *o)
{
	static int				i = 0;
	int						bit;
	static unsigned char	c = 0;

	(void)o;
	if (num_server == SIGUSR1)
		bit = 1;
	else if (num_server == SIGUSR2)
		bit = 0;
	else
		exit(-1);
	c += bit << i++;
	if (i == 8)
	{
		write (1, &c, 1);
		i = 0;
		c = 0;
	}
	kill (inf->si_pid, SIGUSR1);
}

int	main(void)
{	
	struct sigaction	sig;

	ft_printf("Server Pid : %d\n", getpid());
	sig.sa_sigaction = action;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
	{	
		pause();
	}
}
