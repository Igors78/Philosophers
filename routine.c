/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:33:13 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/27 09:37:24 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	drop_forks(t_arg *args, t_phil *phil)
{
	pthread_mutex_lock(&args->access);
	//pthread_mutex_lock(&args->forks[phil->left_fork]);
	args->state[phil->left_fork] = 1;
	//pthread_mutex_unlock(&args->forks[phil->left_fork]);
	//pthread_mutex_lock(&args->forks[phil->right_fork]);
	args->state[phil->right_fork] = 1;
	//pthread_mutex_unlock(&args->forks[phil->right_fork]);
	pthread_mutex_unlock(&args->access);
}

static int	check_cycle(t_arg *args, t_phil *phil)
{
	if (phil->right_fork == phil->left_fork)
	{
		m_print(args, "died", phil->ph_id);
		pthread_mutex_lock(&args->chopchop);
		args->finish++;
		pthread_mutex_unlock(&args->chopchop);
		return (-1);
	}
	if (phil->count == 0)
		phil->last_eat = args->start;
	if (get_time() - phil->last_eat >= args->time_die)
	{
		m_print(args, "died", phil->ph_id);
		pthread_mutex_lock(&args->chopchop);
		args->finish++;
		pthread_mutex_unlock(&args->chopchop);
		return (-1);
	}
	return (0);
}

static void	eat(t_arg *args, t_phil *phil)
{
	phil->last_eat = get_time();
	m_print(args, "eating", phil->ph_id);
	usleep(args->time_eat * 1000);
	drop_forks(args, phil);
	phil->count++;
	m_print(args, "sleeping", phil->ph_id);
	usleep(args->time_sleep * 1000);
	m_print(args, "thinking", phil->ph_id);
}

static void	take_forks(t_arg *args, t_phil *phil)
{
	while (1)
	{
		pthread_mutex_lock(&args->access);
		if (args->state[phil->left_fork] && args->state[phil->right_fork])
		{
			//pthread_mutex_lock(&args->forks[phil->left_fork]);
			args->state[phil->left_fork] = 0;
			//pthread_mutex_unlock(&args->forks[phil->left_fork]);
			m_print(args, "has taken a fork", phil->ph_id);
			//pthread_mutex_lock(&args->forks[phil->right_fork]);
			args->state[phil->right_fork] = 0;
			//pthread_mutex_unlock(&args->forks[phil->right_fork]);
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
	eat(args, phil);
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
		if (check_cycle(args, phil))
			break ;
		take_forks(args, phil);
		printf(RD "TIMES EATEN %d\n" CLR, phil->count);
	}
	return (NULL);
}
