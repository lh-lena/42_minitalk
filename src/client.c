/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:47:49 by ohladkov          #+#    #+#             */
/*   Updated: 2023/10/14 20:12:37 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	send_signals(int pid, char c)
{
	int bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((((unsigned char)c >> bit) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_printf("Failed to send signal");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_printf("Failed to send signal");
		}
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		if (!ft_atoi(argv[1]) || (ft_atoi(argv[1]) <= 100 || ft_atoi(argv[1]) > 32767) || argv[2][0] == 0)
		{
			ft_printf("[ERROR]\nWrong arg or you didn't send any text!");
			return (EXIT_FAILURE);
		}
		while (argv[2][i] != '\0')
		{
			send_signals(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
		send_signals(ft_atoi(argv[1]), '\0');
	}
	else
	{
		ft_printf("[ERROR]\n Expected: ./client <PID> <MESSAGE>");
		return (1);
	}
	return (0);
}