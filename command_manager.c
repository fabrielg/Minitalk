/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:45:55 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 20:25:45 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "command_manager.h"

#define COMMAND_STOP "/stop"
#define COMMAND_EXIT "/exit"
#define COMMAND_LINUX "/linux"
#define COMMAND_HEART "/heart"
#define COMMAND_RAINBOW "/rainbow"
#define COMMAND_QUOI "quoi ?"
#define EMOJI_HEART "<3"
#define EMOJI_HAPPY ":happy:"
#define EMOJI_JOY ":joy:"
#define EMOJI_SKULL ":skull:"
#define EMOJI_SOB ":sob:"
#define EMOJI_UPSIDE ":upside:"

int	apply_command(char *cmd, int pid)
{
	if (!ft_strncmp(cmd, COMMAND_STOP, 5) || !ft_strncmp(cmd, COMMAND_EXIT, 5))
		return (command_exit(cmd), 1);
	else if (!ft_strncmp(cmd, COMMAND_LINUX, 6))
		return (command_linux(pid), 1);
	else if (!ft_strncmp(cmd, COMMAND_HEART, 6))
		return (command_heart(pid), 1);
	else if (!ft_strncmp(cmd, COMMAND_RAINBOW, 8))
		return (command_rainbow(pid), 1);
	else if (!ft_strncmp(cmd, COMMAND_QUOI, 6))
		return (command_quoi(pid), 1);
	else if (!ft_strncmp(cmd, EMOJI_HEART, 2))
		return (emoji_heart(pid), 1);
	else if (!ft_strncmp(cmd, EMOJI_HAPPY, 7))
		return (emoji_happy(pid), 1);
	else if (!ft_strncmp(cmd, EMOJI_JOY, 5))
		return (emoji_joy(pid), 1);
	else if (!ft_strncmp(cmd, EMOJI_SKULL, 7))
		return (emoji_skull(pid), 1);
	else if (!ft_strncmp(cmd, EMOJI_SOB, 5))
		return (emoji_sob(pid), 1);
	else if (!ft_strncmp(cmd, EMOJI_UPSIDE, 8))
		return (emoji_upside(pid), 1);
	return (0);
}
