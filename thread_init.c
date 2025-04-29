/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:16:06 by ccalabro          #+#    #+#             */
/*   Updated: 2025/04/29 18:16:07 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"

void	philos_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_phil)
	{
		pthread_create(&table->phil[i].thread, NULL, &philo_rout,
			(void *)&table->phil[i]);
		i++;
	}
	pthread_create(&table->monitor_id, NULL, &is_monitoring, (void *)table);
	i = 0;
	while (i < table->n_phil)
	{
		pthread_join(table->phil[i].thread, NULL);
		i++;
	}
	pthread_join(table->monitor_id, NULL);
}

void	destroy_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_phil)
	{
		pthread_mutex_destroy(&table->phil[i].is_eating);
		i++;
	}
	free(table->phil);
}
