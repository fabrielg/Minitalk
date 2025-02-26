/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:17:15 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 19:23:44 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

void	command_linux(int pid)
{
	ft_printf(MESSAGE, BLACK_B, YELLOW_B, pid, GREY_B);
	ft_putendl_fd("              a8888b.", 1);
	ft_putendl_fd("             d888888b.", 1);
	ft_putendl_fd("             8P\"YP\"Y88", 1);
	ft_putendl_fd("             8|o||o|88", 1);
	ft_putendl_fd("             8'    .88", 1);
	ft_putendl_fd("             8`._.' Y8.", 1);
	ft_putendl_fd("            d/      `8b.", 1);
	ft_putendl_fd("          .dP   .     Y8b.", 1);
	ft_putendl_fd("         d8:'   \"   `::88b.", 1);
	ft_putendl_fd("        d8\"           `Y88b", 1);
	ft_putendl_fd("       :8P     '       :888", 1);
	ft_putendl_fd("        8a.    :      _a88P", 1);
	ft_putendl_fd("      ._/\"Yaa_ :    .| 88P|", 1);
	ft_putendl_fd("      \\    YP\"      `| 8P  `.", 1);
	ft_putendl_fd("      /     \\._____.d|    .'", 1);
	ft_putendl_fd("      `--..__)888888P`._.'", 1);
}
