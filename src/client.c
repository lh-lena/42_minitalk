/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:00:55 by ohladkov          #+#    #+#             */
/*   Updated: 2023/10/25 20:10:22 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

bool	g_server_sig;

static void	send_bits(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((c >> bit) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				print_error("Failed to send SIGUSR1");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				print_error("Failed to send SIGUSR2");
		}
		while (g_server_sig != true)
			usleep(20);
		bit--;
		g_server_sig = false;
	}
}

static void	send_signals(int pid, char *str)
{
	int	idx;

	idx = 0;
	g_server_sig = false;
	while (str[idx] != '\0')
	{
		send_bits(pid, str[idx]);
		idx++;
	}
	send_bits(pid, '\0');
}

static void	check_signal(int signal)
{
	if (signal == SIGUSR2)
		g_server_sig = true;
	else if (signal == SIGUSR1)
		exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc == 3)
	{
		if (!ft_atoi(argv[1]) || (ft_atoi(argv[1]) <= 100 || \
		ft_atoi(argv[1]) > 4194304) || argv[2][0] == 0)
			print_error("Wrong arguments/you didn't send any text!\n");
	}
	else
		print_error("Expected: ./client <PID> <MESSAGE>");
	sa.sa_handler = &check_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_error("Error sigaction\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		print_error("Error sigaction\n");
	send_signals(ft_atoi(argv[1]), argv[2]);
	return (0);
}
