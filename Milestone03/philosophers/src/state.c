/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:32:00 by drubio-s          #+#    #+#             */
/*   Updated: 2025/09/15 20:10:28 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	one_philo(t_data *data)
{
	pthread_mutex_lock(&data->sim->fork_mutex[data->lh_fork]);
	log_print(data, FORK);
	usleep(data->sim->t_eat);
	pthread_mutex_unlock(&data->sim->fork_mutex[data->lh_fork]);
}

void	philo_die(t_data *data)
{
	long	local_last_meal;
	long	current_time;

	pthread_mutex_lock(&data->meal_mutex);
	local_last_meal = data->last_meal;
	pthread_mutex_unlock(&data->meal_mutex);
	current_time = timestamp(data->sim->start_sim);
	if (current_time - local_last_meal > data->sim->t_die)
	{
		pthread_mutex_lock(&data->sim->dead_mutex);
		data->sim->global_philo_die = 1;
		pthread_mutex_unlock(&data->sim->dead_mutex);
		pthread_mutex_lock(&data->sim->print_mutex);
		printf("%ld %d %s",
			timestamp(data->sim->start_sim), data->id + 1, DEAD);
		pthread_mutex_unlock(&data->sim->print_mutex);
	}
}

void	ft_meals(t_data *data)
{
	pthread_mutex_lock(&data->meal_mutex);
	data->last_meal = timestamp(data->sim->start_sim);
	pthread_mutex_unlock(&data->meal_mutex);
}

void	ft_n_eats(t_data *data)
{
	pthread_mutex_lock(&data->sim->n_eat_mutex);
	data->n_eat++;
	pthread_mutex_unlock(&data->sim->n_eat_mutex);
}

void	log_print(t_data *data, char *arg)
{
	if (!philo_done(data) && !sim_end(data))
	{
		pthread_mutex_lock(&data->sim->print_mutex);
		printf("%ld %d %s", timestamp(data->sim->start_sim), data->id + 1, arg);
		pthread_mutex_unlock(&data->sim->print_mutex);
	}
}
