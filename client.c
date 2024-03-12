/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:23:09 by acherraq          #+#    #+#             */
/*   Updated: 2024/03/09 18:23:10 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    pid_t pid;

    if (argc != 3)
        ft_printf("usage ./client.c <pid> <strings>");
    pid = ft_atoi(argv[1]);

}

int main(int argc, char **argv)
{

}