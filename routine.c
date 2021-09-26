/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:33:13 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/26 14:54:44 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_cycle(t_arg *args, t_phil *phil)
{
	if (phil->right_fork == phil->left_fork)
	{
		m_print(args, "died", phil->ph_id);
		args->finish++;
		return (-1);
	}
	if (phil->count == 0)
		phil->last_eat = phil->startsim;
	if (get_time() - phil->last_eat >= args->time_die)
	{
		m_print(args, "died", phil->ph_id);
		args->finish++;
		return (-1);
	}
	pthread_mutex_unlock(&args->chopchop);
	return (0);
}

static void	take_forks(t_arg *args, t_phil *phil)
{
	if (check_cycle(args, phil))
		return ;
	while (1)
	{
		pthread_mutex_lock(&args->access);
		if (args->state[phil->left_fork] && args->state[phil->right_fork])
		{
			pthread_mutex_lock(&args->forks[phil->left_fork]);
			args->state[phil->left_fork] = 0;
			pthread_mutex_unlock(&args->forks[phil->left_fork]);
			m_print(args, "has taken a fork", phil->ph_id);
			pthread_mutex_lock(&args->forks[phil->right_fork]);
			args->state[phil->right_fork] = 0;
			pthread_mutex_unlock(&args->forks[phil->right_fork]);
			m_print(args, "has taken a fork", phil->ph_id);
			pthread_mutex_unlock(&args->access);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&args->access);
			usleep(10);
		}
	}
}

static void	drop_forks(t_arg *args, t_phil *phil)
{
	pthread_mutex_lock(&args->access);
	pthread_mutex_lock(&args->forks[phil->left_fork]);
	args->state[phil->left_fork] = 1;
	pthread_mutex_unlock(&args->forks[phil->left_fork]);
	pthread_mutex_lock(&args->forks[phil->right_fork]);
	args->state[phil->right_fork] = 1;
	pthread_mutex_unlock(&args->forks[phil->right_fork]);
	pthread_mutex_unlock(&args->access);
}

static void	eat(t_arg *args, t_phil *phil)
{
	phil->last_eat = get_time();
	m_print(args, "eating", phil->ph_id);
	phil->count++;
	usleep(args->time_eat * 1000);
	drop_forks(args, phil);
	m_print(args, "sleeping", phil->ph_id);
	usleep(args->time_sleep * 1000);
	m_print(args, "thinking", phil->ph_id);
}

void	*routine(void *philosoph)
{
	t_arg	*args;
	t_phil	*phil;

	phil = (t_phil *)philosoph;
	args = phil->args;
	while (!(args->finish))
	{
		if (args->num_eat && phil->count == args->num_eat)
			return (NULL);
		take_forks(args, phil);
		if (check_cycle(args, phil))
			return (NULL);
		eat(args, phil);
	}
	return (NULL);
}
