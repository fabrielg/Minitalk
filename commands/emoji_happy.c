/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emoji_happy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:21:15 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/26 20:15:36 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

void	emoji_happy(int pid)
{
	ft_printf(MESSAGE, BLACK_B, YELLOW_B, pid, RESET);
	ft_printf("%s\n", "😊");
}
