/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:09:04 by ccalabro          #+#    #+#             */
/*   Updated: 2025/05/06 18:09:47 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	def_struct_table(t_table *table, int argc, char **argv)
{
	table->n_phil = ft_atoi(argv[1]);
	table->time_before_death = ft_atoi(argv[2]);
	table->time_for_eat = ft_atoi(argv[3]);
	table->time_for_sleep = ft_atoi(argv[4]);
	table->startime = taketime();
	table->is_dead = 0;
	table->enough_meal = 0;
	if (argc == 6)
		table->eat_counter = ft_atoi(argv[5]);
	else
		table->eat_counter = -1;
	pthread_mutex_init(&table->dead_checker, NULL);
	pthread_mutex_init(&table->meal_checker, NULL);
	pthread_mutex_init(&table->printf, NULL);
	init_forks(table);
	def_struct_philo(table);
}
