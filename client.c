/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 17:24:02 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

#define MAX_TRY 100

int	g_bit_waiter = MAX_TRY;

static void	send_bits(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_bit_waiter = MAX_TRY;
		if (kill(pid, (!(c & 0b10000000) * (SIGUSR2 - SIGUSR1) + SIGUSR1)))
		{
			ft_printf(INVALID_PID, RED_B, YELLOW_B, pid, RESET);
			exit(EXIT_FAILURE);
		}
		c = c << 1;
		i++;
		while (--g_bit_waiter > 0)
			usleep(10);
		if (g_bit_waiter == 0)
		{
			ft_printf(TIMEOUT, RED_B, RESET);
			exit(EXIT_FAILURE);
		}
		usleep(10);
	}
}

static void	send_str(char *str, int pid)
{
	while (*str)
	{
		send_bits(*str, pid);
		str++;
	}
	send_bits(0, pid);
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		g_bit_waiter = -1;
	else if (signum == SIGUSR2)
	{
		ft_printf(RECEIVED, GREEN, RESET);
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*str;

	if (ac != 3)
	{
		ft_putendl_fd("Usage: ./client <SERVER PID> <MESSAGE>", 1);
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	str = av[2];
	init_signal(SIGUSR1, signal_handler);
	init_signal(SIGUSR2, signal_handler);
	send_str(str, server_pid);
	ft_printf(NOT_RECEIVED, RED, RESET);
	return (0);
}
