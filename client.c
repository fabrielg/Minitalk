/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 15:25:32 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	int		server_pid;
	char	*str;

	if (ac != 3)
		return (0);
	server_pid = ft_atoi(av[1]);
	str = av[2];
	return (0);
}
