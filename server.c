/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 11:53:28 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	value = 0b0;
	static int	power = 0;

	(void)context;
	if (signum == SIGUSR1)
		value += (128 >> power);
	power++;
	if (power >= 8)
	{
		if (value)
			ft_putchar_fd(value, 1);
		else
		{
			ft_putchar_fd('\n', 1);
			if (kill(info->si_pid, SIGUSR2))
				ft_putstr_fd("ERROR: Can't send confirmation to the pid.\n", 1);
		}
		power = 0;
		value = 0b0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;

	pid = getpid();
	ft_printf("%sServer PID : %s%d%s\n", GREEN_B, YELLOW_B, pid, RESET);
	init_signal(SIGUSR1, signal_handler);
	init_signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
