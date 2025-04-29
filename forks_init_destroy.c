/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:15:07 by ccalabro          #+#    #+#             */
/*   Updated: 2025/04/29 18:15:08 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"

void	initialize_forks(t_table *t)
{
	int	i;

	i = 0;
	t->fork = (pthread_mutex_t *)malloc(t->n_phil * sizeof(pthread_mutex_t));
	if (t->fork == NULL)
	{
		printf("ERROR malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (i < t->n_phil)
	{
		pthread_mutex_init(&t->fork[i], NULL);
		i++;
	}
}

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
