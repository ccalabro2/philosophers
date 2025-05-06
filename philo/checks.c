/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:44:13 by ccalabro          #+#    #+#             */
/*   Updated: 2025/05/06 18:44:30 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_checker(t_table *table)
{
	pthread_mutex_lock(&table->dead_checker);
	if (table->is_dead == 0)
	{
		pthread_mutex_unlock(&table->dead_checker);
		return (0);
	}
	pthread_mutex_unlock(&table->dead_checker);
	return (1);
}

int	food_checker(t_table *table)
{
	pthread_mutex_lock(&table->meal_checker);
	if (table->enough_meal == 0)
	{
		pthread_mutex_unlock(&table->meal_checker);
		return (0);
	}
	pthread_mutex_unlock(&table->meal_checker);
	return (1);
}

void	check_forks(t_philos *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_all("has taken a fork", philo);
		pthread_mutex_lock(philo->left_fork);
		print_all("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_all("has taken a fork", philo);
		pthread_mutex_lock(philo->right_fork);
		print_all("has taken a fork", philo);
	}
}
