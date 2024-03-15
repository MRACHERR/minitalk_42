/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:23:03 by acherraq          #+#    #+#             */
/*   Updated: 2024/03/15 11:43:44 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"


int i = -1;
void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	//exit(EXIT_FAILURE);
    exit(1);
}
void receiver(int bit, pid_t si_pid)
{
    //static int     i;
    static char    c;
    int     shift;

    if (bit == 2)
    {
        i = -1;
        c = 0;
    }
    if (i < 0 || getpid() == si_pid)
    {
        i = 7;
        c = 0;
    }
    shift = 1 << i;
    if (bit == 1)
        c = c | shift;
    i--;
    if (i < 0)
    {
        ft_printf("%c", c);
        // if (c == 0) /*gdggdgdg*/
        //     kill(si_pid, SIGUSR1); /*gdggdgdg*/
    }
    //ft_printf("%i", i);
}

void sig_handler (int sig, siginfo_t *info, void *p)
{
    (void) *p;
    //ft_printf("\nSignal received %i\n", sig);
    // ft_printf("\nSignal received %c\n", c);
    if (sig == SIGUSR1)
        receiver(1, info->si_pid);
    if (sig == SIGUSR2)
        receiver(0, info->si_pid);
    if (sig == SIGINT)
    {
        receiver(2,info->si_pid);
        exit(0);
    //    ft_printf( "Failed to change SIGUSR2's behavior");
    }
     
     //if (sigaction)
     //sleep(10);
}

void    receive_signal()
{
    struct sigaction act;
    struct sigaction act1;
    
    //act.sa_flags = SA_SIGINFO;
    act.sa_flags = SA_SIGINFO; 
    act.sa_sigaction = sig_handler;
    act1.sa_sigaction = sig_handler;
    
	if (sigaction(SIGUSR2, &act, NULL) == -1 || sigaction(SIGUSR1, &act, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
        
    if (sigaction(SIGINT, &act1, NULL) ||
        sigaction(SIGTERM, &act1, NULL))
        {
            act.sa_flags = SA_RESETHAND;
		//handle_errors("Failed to change SIGUSR1's behavior");
        }
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

