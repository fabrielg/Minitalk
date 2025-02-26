/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 14:21:19 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

#define INVALID_PID "%s%sERROR: Can't send confirmation to the pid%s%s %d%s\n"
#define PID "%sServer PID : %s%d%s\n"
#define MESSAGE "\n%sMessage received from PID: %s%d\n%s"

void	display_message(t_strbuilder **message, int pid)
{
	ft_printf(MESSAGE, BLACK_B, YELLOW_B, pid, GREY_B);
	ft_sb_display(*message);
	ft_sb_clear(message);
	*message = NULL;
	ft_printf("%s\n", RESET);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int			value = 0b0;
	static int			power = 0;
	static t_strbuilder	*message = NULL;

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
			display_message(&message, info->si_pid);
			if (kill(info->si_pid, SIGUSR2))
				ft_printf(INVALID_PID, RED_BG, GREY_B, RESET, YELLOW_B,
					info->si_pid, RESET);
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
