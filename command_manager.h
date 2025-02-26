/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:02:55 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 20:24:24 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_MANAGER_H
# define COMMAND_MANAGER_H

int		apply_command(char *cmd, int pid);

void	command_exit(char *cmd);
void	command_heart(int pid);
void	command_quoi(int pid);
void	command_linux(int pid);
void	command_rainbow(int pid);
void	emoji_heart(int pid);
void	emoji_happy(int pid);
void	emoji_joy(int pid);
void	emoji_skull(int pid);
void	emoji_sob(int pid);
void	emoji_upside(int pid);

#endif