/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:38:32 by orauline          #+#    #+#             */
/*   Updated: 2023/02/06 18:38:34 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//converts the initial portion of the string pointed to by str to int representation.

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = 1; 
	res = 0;
	i = 0;
	while (((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		&& str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int main(void)
{
	char *s = "-2147483648";
	printf("%d %d", ft_atoi(s), atoi(s));
	return (0);
}
