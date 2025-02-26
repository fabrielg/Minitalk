/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_quoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:11:39 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 19:23:55 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

void	command_quoi(int pid)
{
	ft_printf(MESSAGE, BLACK_B, YELLOW_B, pid, GREY_B);
	ft_printf("Quoi ? FEUR !!!%s\n", RESET);
}
