/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:23:03 by acherraq          #+#    #+#             */
/*   Updated: 2024/03/17 15:36:32 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_i = -1;

void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void	receiver(int bit, pid_t si_pid)
{
	static pid_t	old_si_pid;
	static char		c;
	int				shift;

	if (g_i == -1)
		old_si_pid = -1;
	if (bit == 2)
	{
		g_i = -1;
		c = 0;
	}
	if (g_i < 0 || old_si_pid != si_pid)
	{
		g_i = 7;
		c = 0;
	}
	shift = 1 << g_i;
	if (bit == 1)
		c = c | shift;
	g_i--;
	if (g_i < 0)
	{
		ft_printf("%c", c);
        if (c == 0) /*gdggdgdg*/
            kill(si_pid, SIGUSR1); /*gdggdgdg*/
	}
	old_si_pid = si_pid;
}

void	sig_handler(int sig, siginfo_t *info, void *p)
{
	(void)*p;
	if (sig == SIGUSR1)
		receiver(1, info->si_pid);
	if (sig == SIGUSR2)
		receiver(0, info->si_pid);
}

void	receive_signal(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR2, &act, NULL) == -1 || sigaction(SIGUSR1, &act,
			NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	ft_printf("Server PID : %i\n", getpid());
	receive_signal();
	while (1)
		pause();
	return (0);
}
