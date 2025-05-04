/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:29:09 by ccalabro          #+#    #+#             */
/*   Updated: 2025/05/04 16:33:05 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(t_table *table)
{
	int	c;

	c = 0;
	while (c < table->n_phil)
	{
		pthread_mutex_destroy(&table->fork[c]);
		c++;
	}
	free(table->fork);
}
