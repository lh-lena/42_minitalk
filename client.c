/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:47:49 by ohladkov          #+#    #+#             */
/*   Updated: 2023/09/15 13:57:12 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	int	letter;
	int i;

	letter = 0;
	while(message[letter])
	{
		i = -1;
		while (++i < 8)
		{
			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
		letter++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		unsleep(50);
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		process_id;

	if (argc == 3)
	{
		process_id = ft_atoi(argv[1]);
		if (!process_id)
		{
			ft_printf("[ERROR]. Wrong arg");
			return (0);
		}
		message = argv[2];
		if (message[0] == 0)
		{
			ft_printf("You didn't send any text!");
			return (0);
		}
		send_signals(process_id, message);
	}
	else
	{
		ft_printf("[ERROR]. Too much or too few arguments.\n Make sure ");
		ft_printf("you enter arguments as follow: ./client <PID> <MESSAGE>");
	}
	return (0);
}