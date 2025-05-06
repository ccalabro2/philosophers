/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atois_and_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:15:40 by ccalabro          #+#    #+#             */
/*   Updated: 2025/05/06 19:02:29 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10;
		result += (*str++ - '0');
	}
	return (sign * result);
}

int	atoi_for_check(const char *str)
{
	int	result;

	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
		{
			write(1, "ERROR number is negative\n", 25);
			return (1);
		}
	}
	while (ft_isdigit(*str))
	{
		result = result * 10;
		result += (*str++ - '0');
	}
	return (0);
}

int	checks(int argc, char **argv)
{
	if (argc > 6 || argc < 5)
		return (printf("ERROR: argc is wrong\n"), 1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		return (printf("ERROR: nphilo is wrong\n"), 1);
	else if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0)
	{
		return (printf("ERROR: time is wrong\n"), 1);
	}
	else if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
			return (printf("ERROR: wrong eat counter\n"), 1);
	}
	return (0);
}
