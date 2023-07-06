/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:42:24 by orauline          #+#    #+#             */
/*   Updated: 2023/07/05 14:52:06 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void    split_char(int pid, char c)
{
    int bit;

    bit = 7;
    while (bit >= 0)
    {
       if (c & (1 << bit))
	   		kill(pid, SIGUSR1);
       else
    		kill(pid, SIGUSR2);
		usleep(200);
		bit--;
    }
}

void    split_str(int pid, char *str)
{
    int i;
    
	i = 0;
    while (str[i])
	{
        split_char(pid, str[i]);
        i++;
	}
	split_char(pid, 0);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        split_str(ft_atoi(argv[1]), argv[2]);
    }
    return (0);
}