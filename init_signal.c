/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:12:58 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/25 19:29:52 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>
#include <bits/sigaction.h>

void	init_signal(int signum, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	(void)signum;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if ((sigaction(SIGUSR1, &sa, 0)) == -1)
		ft_putendl_fd("Error sigaction", 2);
	else if ((sigaction(SIGUSR2, &sa, 0)) == -1)
		ft_putendl_fd("Error sigaction", 2);
}
