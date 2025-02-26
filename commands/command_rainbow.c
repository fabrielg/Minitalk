/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rainbow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:21:15 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 20:12:04 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

void	command_rainbow(int pid)
{
	ft_printf(MESSAGE, BLACK_B, YELLOW_B, pid, RESET);
	ft_printf("     %s_.-\"\"\"\"`-._ \n", RED_B);
	ft_printf("   %s,' %s_-\"\"\"\"`-_ %s`.\n", RED_B, YELLOW_B, RED_B);
	ft_printf("  %s/ %s,'%s.-'\"\"\"`-.%s`. %s\\\n", RED_B, YELLOW_B, GREEN_B, \
		YELLOW_B, RED_B);
	ft_printf(" %s| %s/ %s/ %s,'\"\"\"`. %s\\ %s\\ %s|\n", RED_B, YELLOW_B, \
		GREEN_B, CYAN_B, GREEN_B, YELLOW_B, RED_B);
	ft_printf("%s| %s| %s| %s| %s,'\"`. %s| %s| %s| %s|\n", RED_B, YELLOW_B, \
		GREEN_B, CYAN_B, PURPLE_B, CYAN_B, GREEN_B, YELLOW_B, RED_B);
	ft_printf("%s| %s| %s| %s| %s|   | %s| %s| %s| %s|\n", RED_B, YELLOW_B, \
		GREEN_B, CYAN_B, PURPLE_B, CYAN_B, GREEN_B, YELLOW_B, RED_B);
	ft_putstr_fd(RESET, 1);
}
