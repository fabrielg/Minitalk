/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:45:55 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 19:42:20 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "command_manager.h"

#define COMMAND_STOP "/stop"
#define COMMAND_EXIT "/exit"
#define COMMAND_LINUX "/linux"
#define COMMAND_HEART "/heart"
#define COMMAND_QUOI "quoi ?"
#define EMOJI_HEART "<3"

int	apply_command(char *cmd, int pid)
{
	if (!ft_strncmp(cmd, COMMAND_STOP, 5) || !ft_strncmp(cmd, COMMAND_EXIT, 5))
		return (command_exit(cmd), 1);
	else if (!ft_strncmp(cmd, COMMAND_LINUX, 6))
		return (command_linux(pid), 1);
	else if (!ft_strncmp(cmd, COMMAND_HEART, 6))
		return (command_heart(pid), 1);
	else if (!ft_strncmp(cmd, COMMAND_QUOI, 6))
		return (command_quoi(pid), 1);
	else if (!ft_strncmp(cmd, EMOJI_HEART, 2))
		return (emoji_heart(pid), 1);
	return (0);
}
