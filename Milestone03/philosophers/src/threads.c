/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:34:51 by drubio-s          #+#    #+#             */
/*   Updated: 2025/09/15 20:10:13 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (data->sim->n_philo == 1)
		one_philo(data);
	else
	{
		while (1)
		{
			if (data->id % 2 != 0)
				usleep(1000);
			philo_eat(data);
			if (philo_done(data) || sim_end(data))
			{
				pthread_mutex_lock(&data->sim->state_mutex);
				data->sim->global_philo_done++;
				pthread_mutex_unlock(&data->sim->state_mutex);
				return (NULL);
			}
			philo_sleep(data);
			philo_think(data);
		}
	}
	return (NULL);
}

void	*keeper_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (!stop_keeper(data))
	{
		usleep(10000);
		i = 0;
		while (i < data->sim->n_philo && !stop_keeper(data))
		{
			philo_die(&data[i]);
			i++;
		}
	}
	return (NULL);
}

int	stop_keeper(t_data *data)
{
	pthread_mutex_lock(&data->sim->state_mutex);
	if (data->sim->global_philo_done == data->sim->n_philo || sim_end(data))
	{
		pthread_mutex_unlock(&data->sim->state_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->sim->state_mutex);
	return (0);
}

int	philo_done(t_data *data)
{
	int	local_n_eat;

	pthread_mutex_lock(&data->sim->n_eat_mutex);
	local_n_eat = data->n_eat;
	pthread_mutex_unlock(&data->sim->n_eat_mutex);
	if (local_n_eat == data->sim->max_eat)
		return (1);
	return (0);
}

int	sim_end(t_data *data)
{
	pthread_mutex_lock(&data->sim->dead_mutex);
	if (data->sim->global_philo_die)
	{
		pthread_mutex_unlock(&data->sim->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->sim->dead_mutex);
	return (0);
}
