/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 11:30:27 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

#define MAX_TRY 100

int	g_bit_waiter = MAX_TRY;

void	send_bits(int c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_bit_waiter = MAX_TRY;
		if (c & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c << 1;
		i++;
		while (--g_bit_waiter > 0)
			usleep(100);
		if (g_bit_waiter == 0)
		{
			ft_putstr_fd("Failed to send byte: timeout\n", 1);
			exit(EXIT_FAILURE);
		}
		usleep(100);
	}
}

void	send_str(char *str, int pid)
{
	while (*str)
	{
		send_bits(*str, pid);
		str++;
	}
	send_bits(0, pid);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		g_bit_waiter = -1;
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("Message received !\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*str;

	if (ac != 3)
		return (0);
	server_pid = ft_atoi(av[1]);
	str = av[2];
	init_signal(SIGUSR1, signal_handler);
	init_signal(SIGUSR2, signal_handler);
	send_str(str, server_pid);
	return (0);
}
