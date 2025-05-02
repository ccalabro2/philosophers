/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_init_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:15:07 by ccalabro          #+#    #+#             */
/*   Updated: 2025/05/02 17:57:06 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_phil)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
	free(table->fork);
}

void	initialize_forks(t_table *table)
{
	int	i;

	i = 0;
	table->fork = (pthread_mutex_t *)malloc(table->n_phil
			* sizeof(pthread_mutex_t));
	if (table->fork == NULL)
	{
		printf("ERROR: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (i < table->n_phil)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		i++;
	}
}
