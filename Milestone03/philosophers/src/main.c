/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:19:39 by drubio-s          #+#    #+#             */
/*   Updated: 2025/09/15 19:57:30 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_mutex(t_sim *sim)
{
	int	i;

	i = 0;
	sim->fork_mutex = malloc(sizeof (pthread_mutex_t) * sim->n_philo);
	pthread_mutex_init(&sim->print_mutex, NULL);
	pthread_mutex_init(&sim->n_eat_mutex, NULL);
	pthread_mutex_init(&sim->state_mutex, NULL);
	pthread_mutex_init(&sim->dead_mutex, NULL);
	while (i < sim->n_philo)
	{
		pthread_mutex_init(&sim->fork_mutex[i], NULL);
		i++;
	}
}

void	init_threads(t_sim *sim)
{
	int	i;

	i = 0;
	sim->data = malloc(sizeof (t_data) * sim->n_philo);
	while (i < sim->n_philo)
	{
		sim->data[i].sim = sim;
		sim->data[i].id = i;
		sim->data[i].lh_fork = i;
		sim->data[i].rh_fork = (i + 1) % sim->n_philo;
		sim->data[i].last_meal = timestamp(sim->start_sim);
		sim->data[i].n_eat = 0;
		pthread_mutex_init(&sim->data[i].meal_mutex, NULL);
		pthread_create(&sim->data[i].philo, NULL, philo_routine, &sim->data[i]);
		i++;
	}
	pthread_create(&sim->keeper, NULL, keeper_routine, sim->data);
	i = 0;
	while (i < sim->n_philo)
	{
		pthread_join(sim->data[i].philo, NULL);
		i++;
	}
	pthread_join(sim->keeper, NULL);
	destroy_mutexes(sim);
}

void	free_memory(t_sim *sim)
{
	free(sim->fork_mutex);
	free(sim->data);
}

void	destroy_mutexes(t_sim *sim)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&sim->n_eat_mutex);
	pthread_mutex_destroy(&sim->print_mutex);
	pthread_mutex_destroy(&sim->state_mutex);
	pthread_mutex_destroy(&sim->dead_mutex);
	while (i < sim->n_philo)
	{
		pthread_mutex_destroy(&sim->fork_mutex[i]);
		pthread_mutex_destroy(&sim->data[i].meal_mutex);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (check_args(argc, argv))
		return (1);
	sim.n_philo = ft_atoi(argv[1]);
	sim.t_die = ft_atoi(argv[2]);
	sim.t_eat = ft_atoi(argv[3]) * 1000;
	sim.t_sleep = ft_atoi(argv[4]) * 1000;
	sim.max_eat = -1;
	if (argc == 6)
		sim.max_eat = ft_atoi(argv[5]);
	sim.start_sim = get_current_time_ms();
	sim.global_philo_done = 0;
	sim.global_philo_die = 0;
	init_mutex(&sim);
	init_threads(&sim);
	free_memory(&sim);
	return (0);
}
