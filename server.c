/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:23:03 by acherraq          #+#    #+#             */
/*   Updated: 2024/03/14 14:32:37 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	//exit(EXIT_FAILURE);
    exit(1);
}

void sig_handler (int sig)
     {
     ft_printf("\nSignal received %i\n", sig );
     //if (sigaction)
     //sleep(10);
     }

void    receive_signal()
{
    struct sigaction act;
    act.sa_flags = SA_SIGINFO;
    act.sa_handler= &sig_handler;
    if (sigaction(SIGUSR1, &act, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int main()
{
    ft_printf("Server PID : %i\n", getpid());
    receive_signal();
    while(1)
    {
        pause();
    }    
}

