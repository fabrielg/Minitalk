/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:02:55 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 18:17:07 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_MANAGER_H
# define COMMAND_MANAGER_H

int		apply_command(char *cmd, int pid);

void	command_exit(char *cmd);
void	command_heart(int pid);
void	command_quoi(int pid);
void	command_linux(int pid);

#endif