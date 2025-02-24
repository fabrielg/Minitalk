/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 15:25:24 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\e[%imServer PID : \e[%im%d\n", 32, 33, pid);
	return (0);
}
