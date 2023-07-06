/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:46:39 by orauline          #+#    #+#             */
/*   Updated: 2023/07/05 14:46:35 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "includes/minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	new_str = (char*)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (s1 && *s1)
		new_str[i++] = *(s1++);
	while (s2 && *s2)
		new_str[i++] = *(s2++);
	new_str[i] = '\0';
	return (new_str);
}

void	show_str(char *str)
{
	printf("%s", str);
	fflush(stdout);
}

char *fill_str(char *str, char c)
{
	char *new;
	char *final_str;
	
	new = malloc(2);
	new[0] = c;
	new[1] = 0;
	final_str = ft_strjoin(str, new);
	free(new);
	return (final_str);
}

void	signal_handler(int sig)
{
	static char c = 0;
	static int	bit_index = -1;
	static	char *str;
	
	if (bit_index < 0)
	{
		bit_index = __CHAR_BIT__ * sizeof(c) - 1;
	}
	if (sig == SIGUSR1)
		c |= 1 << bit_index;
	else
		c &= ~(1 << bit_index);
	if (!bit_index && c)
		str = fill_str(str, c);
	else if (!bit_index && !c)
	{
		show_str(str);
		free(str);
	}
	bit_index--;
}

int main(int argc, char **argv)
{
	(void) argc;
	(void) **argv;
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	printf("Server PID : %d\n", getpid());
	while (1)
		;
	return (0);
}