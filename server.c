/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 18:07:49 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"
#include "command_manager.h"
#include <unistd.h>
#include <signal.h>

static void	display_message(t_strbuilder **build, int pid)
{
	char	*message;

	message = ft_sb_build(*build);
	ft_sb_clear(build);
	*build = NULL;
	if (!message)
		return ;
	if (!apply_command(message, pid))
	{
		ft_printf(MESSAGE, BLACK_B, YELLOW_B, pid, GREY_B);
		ft_printf("%s%s\n", message, RESET);
	}
	free(message);
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	value = 0b0;
	static int				power = 0;
	static t_strbuilder		*message = NULL;

	(void)context;
	if (message == NULL)
		message = ft_sb_new();
	if (signum == SIGUSR1)
		value += (128 >> power);
	power++;
	if (power >= 8)
	{
		ft_sb_add_char(message, value);
		if (!value)
		{
			if (kill(info->si_pid, SIGUSR2))
				ft_printf(CONFIRM_ERR, RED_BG, GREY_B, RESET, YELLOW_B,
					info->si_pid, RESET);
			display_message(&message, info->si_pid);
		}
		power = 0;
		value = 0b0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf(PID, GREEN_B, YELLOW_B, pid, RESET);
	init_signal(SIGUSR1, signal_handler);
	init_signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
