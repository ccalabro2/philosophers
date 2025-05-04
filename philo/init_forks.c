/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:21:11 by ccalabro          #+#    #+#             */
/*   Updated: 2025/05/04 16:36:34 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_table *table)
{
	int	c;

	c = 0;
	table->fork = (pthread_mutex_t *)malloc(table->n_phil
			* sizeof(pthread_mutex_t));
	if (table->fork == NULL)
	{
		printf("ERROR: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (c < table->n_phil)
	{
		pthread_mutex_init(&table->fork[c], NULL);
		c++;
	}
}
