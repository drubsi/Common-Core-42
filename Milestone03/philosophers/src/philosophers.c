/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:35:51 by drubio-s          #+#    #+#             */
/*   Updated: 2025/09/15 19:48:24 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_eat(t_data *data)
{
	lock_forks(data);
	ft_meals(data);
	log_print(data, EAT);
	usleep(data->sim->t_eat);
	unlock_forks(data);
	ft_n_eats(data);
}

void	philo_sleep(t_data *data)
{
	log_print(data, SLEEP);
	usleep(data->sim->t_sleep);
}

void	philo_think(t_data *data)
{
	log_print(data, THINK);
}

void	lock_forks(t_data *data)
{
	if (data->lh_fork < data->rh_fork)
	{
		pthread_mutex_lock(&data->sim->fork_mutex[data->lh_fork]);
		log_print(data, FORK);
		pthread_mutex_lock(&data->sim->fork_mutex[data->rh_fork]);
		log_print(data, FORK);
	}
	else
	{
		pthread_mutex_lock(&data->sim->fork_mutex[data->rh_fork]);
		log_print(data, FORK);
		pthread_mutex_lock(&data->sim->fork_mutex[data->lh_fork]);
		log_print(data, FORK);
	}
}

void	unlock_forks(t_data *data)
{
	if (data->lh_fork < data->rh_fork)
	{
		pthread_mutex_unlock(&data->sim->fork_mutex[data->rh_fork]);
		pthread_mutex_unlock(&data->sim->fork_mutex[data->lh_fork]);
	}
	else
	{
		pthread_mutex_unlock(&data->sim->fork_mutex[data->lh_fork]);
		pthread_mutex_unlock(&data->sim->fork_mutex[data->rh_fork]);
	}
}
