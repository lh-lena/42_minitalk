/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:01:32 by ohladkov          #+#    #+#             */
/*   Updated: 2023/10/25 19:57:22 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

static void	ft_kill(int pid, int signal)
{
	if (signal == SIGUSR1)
	{
		if (kill(pid, SIGUSR1) == -1)
			print_error("Server failed to send a signal");
	}
	else if (signal == SIGUSR2)
	{
		if (kill(pid, SIGUSR2) == -1)
			print_error("Server failed to send a signal");
	}
}

static void	bin_to_char(int signal, char *c)
{
	if (signal == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signal == SIGUSR2)
		*c = *c << 1;
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	pid;
	static int	i;
	static char	c;

	(void)context;
	(void)signal;
	pid = info->si_pid;
	bin_to_char(signal, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			write(1, "\n", 1);
			ft_kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	ft_kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_action;
	static int			pid;

	(void)argv;
	if (argc != 1)
		print_error("Too many arguments");
	pid = getpid();
	ft_printf("Server PID:  %d\n", pid);
	sig_action.sa_sigaction = handle_signal;
	sig_action.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sig_action.sa_mask);
	if (sigaction(SIGUSR1, &sig_action, 0) == -1)
		print_error("Error sigaction\n");
	if (sigaction(SIGUSR2, &sig_action, 0) == -1)
		print_error("Error sigaction\n");
	while (1)
		pause();
	return (0);
}
