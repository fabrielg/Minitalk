/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 20:59:03 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <bits/sigaction.h>

void	signal_handler(int signum)
{
	static int	value = 0b0;
	static int	power = 0;

	if (signum == SIGUSR1)
		value += (128 >> power);
	power++;
	if (power >= 8)
	{
		if (value)
			ft_putchar_fd(value, 1);
		else
			ft_putchar_fd('\n', 1);
		power = 0;
		value = 0b0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("\e[%imServer PID : \e[%im%d\n", 32, 33, pid);
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if ((sigaction(SIGUSR1, &sa, 0)) == -1)
		ft_putendl_fd("Error sigaction", 2);
	if ((sigaction(SIGUSR2, &sa, 0)) == -1)
		ft_putendl_fd("Error sigaction", 2);
	while (1)
		pause();
	return (0);
}
