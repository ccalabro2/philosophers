/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:15:48 by ccalabro          #+#    #+#             */
/*   Updated: 2025/05/06 18:45:32 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(void)
{
	printf("philo is thinking\n");
	exit(EXIT_FAILURE);
}

void	*philo_routine(void *to_cast)
{
	t_philos	*philos;

	philos = (t_philos *)to_cast;
	while ((dead_checker(philos->table) == 0)
		&& (food_checker(philos->table) == 0))
	{
		print_all("is thinking", philos);
		usleep(5 * 1000);
		print_all("is sleeping", philos);
		usleep(philos->table->time_for_sleep * 1000);
		check_forks(philos);
		pthread_mutex_lock(&philos->is_eating);
		print_all("is eating", philos);
		philos->check_time_eat = taketime();
		philos->input_counter++;
		usleep(philos->table->time_for_eat * 1000);
		pthread_mutex_unlock(&philos->is_eating);
		pthread_mutex_unlock(philos->right_fork);
		pthread_mutex_unlock(philos->left_fork);
	}
	return (NULL);
}
