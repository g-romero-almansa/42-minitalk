/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:53:26 by gromero-          #+#    #+#             */
/*   Updated: 2022/06/21 12:08:37 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	num;

	num = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	num = num * neg;
	if (neg > 0 && num < 0)
		return (-1);
	if (neg < 0 && num > 0)
		return (0);
	return (num);
}

void	confirm(int num_client)
{
	if (num_client == SIGUSR1)
		write(1, "ack ", 4);
}

void	send_tab(int pid)
{
	char	c;
	int		bit;

	c = '\n';
	bit = -1;
	while (++bit < 8)
	{
		if (c % 2 == 1)
			kill (pid, SIGUSR1);
		else if (c % 2 == 0)
			kill (pid, SIGUSR2);
		c /= 2;
		usleep(100);
	}
}

void	send_message(int pid, char *s)
{
	int	bit;
	int	i;
	int	c;

	i = -1;
	while (s[++i])
	{	
		bit = -1;
		c = (unsigned char)s[i];
		while (++bit < 8)
		{		
			if (c % 2 == 1)
				kill (pid, SIGUSR1);
			else if (c % 2 == 0)
				kill (pid, SIGUSR2);
			c /= 2;
			usleep(100);
		}
	}
	send_tab(pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Pasa un numero de argumentos validos");
		return (0);
	}
	signal(SIGUSR1, confirm);
	send_message(ft_atoi(argv[1]), argv[2]);
}
