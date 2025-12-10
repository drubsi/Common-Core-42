/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:13:18 by drubio-s          #+#    #+#             */
/*   Updated: 2025/09/15 20:09:51 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define FORK " has taken a fork\n"
# define EAT " is eating\n"
# define SLEEP " is sleeping\n"
# define THINK " is thinking\n"
# define DEAD " is dead\n"

typedef struct s_data	t_data;

typedef struct s_sim
{
	t_data				*data;
	pthread_t			keeper;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					max_eat;
	pthread_mutex_t		print_mutex; //->log_print (general)
	pthread_mutex_t		*fork_mutex; //->lockforks, unlockforks
	pthread_mutex_t		n_eat_mutex; // ->ft_n_eats->variable n_eat (local)
	pthread_mutex_t		state_mutex; // philo_routine -> variable philo_done;
	pthread_mutex_t		dead_mutex; //philo_die ->
	int					global_philo_done;
	int					global_philo_die;
	long long			start_sim;
}	t_sim;

typedef struct s_data
{
	t_sim				*sim;
	pthread_t			philo;
	pthread_mutex_t		meal_mutex; // ->ft_meals->variable last_meal (local)
	int					id;
	int					rh_fork;
	int					lh_fork;
	long long			last_meal;
	int					n_eat;
	//int					done; ->borrar?
}	t_data;

// Argument checking and parsing

int			check_args(int argc, char **argv);
int			ft_is_space(char character);
int			ft_atoi(char *str);
int			ft_error(const char *arg);
int			is_digit(char *argv);

// Initialization and cleanup

void		init_mutex(t_sim *sim);
void		init_threads(t_sim *sim);
void		free_memory(t_sim *sim);
void		destroy_mutexes(t_sim *sim);

// Time functions

long int	get_current_time_ms(void);
long		timestamp(long long startime);

// Philosophers actions

void		one_philo(t_data *data);
void		philo_eat(t_data *data);
void		philo_sleep(t_data *data);
void		philo_think(t_data *data);
void		lock_forks(t_data *data);
void		unlock_forks(t_data *data);

//State managament

void		ft_n_eats(t_data *data);
void		ft_meals(t_data *data);
int			philo_done(t_data *data);
void		philo_die(t_data *data);
int			stop_keeper(t_data *data);
int			sim_end(t_data *data);

// Threading routines

void		*keeper_routine(void *arg);
void		*philo_routine(void *arg);

// Logging

void		log_print(t_data *data, char *arg);

#endif