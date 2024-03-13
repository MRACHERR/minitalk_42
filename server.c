/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:23:03 by acherraq          #+#    #+#             */
/*   Updated: 2024/03/13 12:44:44 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void sig_handler (int sig)
     {
     ft_printf("\nSignal received %i\n", sig );
     sleep(10);
     }

int main()
{
    ft_printf("Server PID : %i\n", getpid());
    // while(1)
    // {
    //     sleep(2);
    //     system("clear");
    // }
    int seconds;
    seconds = 0;
//Step 3
//declaration of structures and zeroing.
struct sigaction act = { 0 };
//Step 4
//sets sig_handler as a new action.
act.sa_handler = &sig_handler;
//Step 5
//Call sigaction()
sigaction (SIGUSR2,&act, NULL);
//Step 6
//Infinite loop
while (1){

//ft_printf("The %i process has been active for:\n%i seconds\n", getpid(), seconds );

    //sleep(2);
    //seconds = seconds+2;
   //system ("clear");
}
}

