/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:15:54 by ccalabro          #+#    #+#             */
/*   Updated: 2025/04/29 18:21:26 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philos	t_philos;

typedef struct s_table
{
	int				n_phil;
	int				is_dead;
	int				enough_meal;
	int				time_before_death;
	int				time_for_eat;
	int				time_for_sleep;
	int				eat_counter;
	size_t			startime;
	t_philos		*phil;
	pthread_t		monitor_id;
	pthread_mutex_t	*fork;
	pthread_mutex_t	dead_checker;
	pthread_mutex_t	meal_checker;
	pthread_mutex_t	printf;
}	t_table;

typedef struct s_philos
{
	int				id;
	int				input_counter;
	size_t			check_time_eat;
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philos;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		is_it_dead(t_table *table);
int		main(int argc, char **argv);
int		enough_meal(t_table *table);
int		food_checker(t_table *table);
int		dead_checker(t_table *table);
int		checks(int argc, char **argv);
int		atoi_for_check(const char *str);
void	one_philo(void);
void	*philo_rout(void *to_cast);
void	philos_init(t_table *table);
void	check_forks(t_philos *philo);
void	destroy_philo(t_table *table);
void	destroy_forks(t_table *table);
void	*is_monitoring(void *to_cast);
void	def_struct_philo(t_table *table);
void	initialize_forks(t_table *table);
void	print_all(char *str, t_philos *phil);
void	def_struct_table(t_table *main, int argc, char **argv);
size_t	taketime(void);
