/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_heart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:21:15 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 19:47:55 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

void	command_heart(int pid)
{
	ft_printf(MESSAGE, BLACK_B, YELLOW_B, pid, RED_B);
	ft_putendl_fd("        @@@@@@           @@@@@@", 1);
	ft_putendl_fd("      @@@@@@@@@@       @@@@@@@@@@", 1);
	ft_putendl_fd("    @@@@@@@@@@@@@@   @@@@@@@@@@@@@@", 1);
	ft_putendl_fd("  @@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("      @@@@@@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("        @@@@@@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("          @@@@@@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("            @@@@@@@@@@@@@@@", 1);
	ft_putendl_fd("              @@@@@@@@@@@", 1);
	ft_putendl_fd("               @@@@@@@", 1);
	ft_putendl_fd("                  @@@", 1);
	ft_putendl_fd("                   @", 1);
	ft_putstr_fd(RESET, 1);
}
