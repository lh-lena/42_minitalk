/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:46:46 by ohladkov          #+#    #+#             */
/*   Updated: 2023/10/14 19:32:31 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// handler that receives information about the signal number, information about the signal delivery, and information about the thread context

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	byte;

	(void)info;
	(void)context;

	if (signal == SIGUSR1)
		byte = byte | (128 >> i);
	i++;
	if (i == 8)
	{
		if (byte)
			ft_putchar_fd(byte, 1);
		else
			ft_putchar_fd('\n', 1);
		i = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_action;
	int					pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("[Error]\nToo many arguments");
		return(1);
	}
	pid = getpid();
	ft_printf("Server PID:  %d\n", pid);
	sig_action.sa_sigaction = handle_signal;
	sig_action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sig_action.sa_mask);
	if (sigaction(SIGUSR1, &sig_action, 0) == -1)
		ft_printf("Error sigaction\n");
	if (sigaction(SIGUSR2, &sig_action, 0) == -1)
		ft_printf("Error sigaction\n");
	while (1)
		pause();
	return (0);
}