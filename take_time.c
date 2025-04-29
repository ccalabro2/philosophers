/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:16:02 by ccalabro          #+#    #+#             */
/*   Updated: 2025/04/29 18:16:03 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"

size_t	taketime(void)
{
	struct timeval	str;
	size_t			rest;

	gettimeofday(&str, NULL);
	rest = (str.tv_sec * 1000) + (str.tv_usec / 1000);
	return (rest);
}
