/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:23:09 by acherraq          #+#    #+#             */
/*   Updated: 2024/04/01 12:06:20 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void	check_argument(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		handle_errors("invalid number of argument");
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			handle_errors("INVALID PID");
		i++;
	}
}

int	send(pid_t pid, char c)
{
	int	i;
	int	shift;

	i = 7;
	shift = 0;
	while (i >= 0)
	{
		shift = 1 << i;
		if (shift & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				handle_errors("Failed to send signal");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				handle_errors("Failed to send signal");
		}
		usleep(70);
		usleep(40);
		i--;
	}
	return (0);
}

int	send_message(pid_t pid, char *msg)
{
	int	i;

	i = 0;
	if (pid == 0)
		handle_errors("invalid pid");
	if (kill(pid, 0) == -1)
		handle_errors("invalid id");
	while (msg[i])
	{
		send(pid, msg[i]);
		i++;
	}
	send(pid, msg[i]);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	check_argument(argc, argv);
	pid = ft_atoi(argv[1]);
	if (pid > MAX_PID)
		handle_errors("INVALID PID");
	send_message(pid, argv[2]);
	return (0);
}
