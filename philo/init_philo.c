/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:15:18 by ccalabro          #+#    #+#             */
/*   Updated: 2025/05/06 18:17:44 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	def_struct_philo(t_table *table)
{
	int	i;

	i = 0;
	table->phil = (t_philos *) malloc(table->n_phil * sizeof(t_philos));
	if (!table->phil)
	{
		printf("ERROR: allocation failed\n");
		exit(EXIT_FAILURE);
	}
	while (i < table->n_phil)
	{
		table->phil[i].id = i + 1;
		table->phil[i].right_fork = &table->fork[i];
		if (i == table->n_phil - 1)
			table->phil[i].left_fork = &table->fork[0];
		else
			table->phil[i].left_fork = &table->fork[i + 1];
		table->phil[i].input_counter = 0;
		table->phil[i].check_time_eat = table->startime;
		table->phil[i].table = table;
		pthread_mutex_init(&table->phil[i].is_eating, NULL);
		i++;
	}
}
