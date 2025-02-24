/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 20:59:19 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <signal.h>

void	send_bits(int c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c << 1;
		i++;
		usleep(1000);
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

int	main(int ac, char **av)
{
	int		server_pid;
	char	*str;

	if (ac != 3)
		return (0);
	server_pid = ft_atoi(av[1]);
	str = av[2];
	send_str(str, server_pid);
	return (0);
}
