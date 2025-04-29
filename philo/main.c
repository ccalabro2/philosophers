/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:15:24 by ccalabro          #+#    #+#             */
/*   Updated: 2025/04/29 18:38:20 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	main;

	if (checks(argc, argv) == 0)
	{
		if (atoi(argv[1]) == 1)
			one_philo();
		def_struct_table(&main, argc, argv);
		philos_init(&main);
		destroy_forks(&main);
		destroy_philo(&main);
	}
	return (0);
}
