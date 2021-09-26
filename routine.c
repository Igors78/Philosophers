/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:33:13 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/26 09:40:59 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_cycle(t_arg *args, t_phil *phil)
{
	if (phil->count == 0)
		phil->last_eat = args->start;
	if (args->finish)
		return (-1);
	if (get_time() - phil->last_eat >= args->time_die)
	{
		args->finish++;
		m_print(args, "died", phil->ph_id);
		return (-1);
	}
	return (0);
}

static void	take_forks(t_arg *args, t_phil *phil)
{
	pthread_mutex_lock(&args->access);
	if (check_cycle(args, phil))
		return ;
	pthread_mutex_lock(&args->forks[phil->left_fork]);
	if (check_cycle(args, phil))
		return ;
	m_print(args, "has taken a fork", phil->ph_id);
	if (phil->right_fork == phil->left_fork)
	{
		pthread_mutex_unlock(&args->forks[phil->left_fork]);
		pthread_mutex_unlock(&args->access);
		args->finish++;
		m_print(args, "died", phil->ph_id);
		return ;
	}
	pthread_mutex_lock(&args->forks[phil->right_fork]);
	m_print(args, "has taken a fork", phil->ph_id);
	pthread_mutex_unlock(&args->access);
}

static void	eat(t_arg *args, t_phil *phil)
{
	if (check_cycle(args, phil))
		return ;
	pthread_mutex_lock(&args->chopchop);
	phil->last_eat = get_time();
	m_print(args, "eating", phil->ph_id);
	while (get_time() - phil->last_eat < args->time_eat)
		usleep(10);
	phil->count++;
	pthread_mutex_unlock(&args->chopchop);
	pthread_mutex_unlock(&args->forks[phil->right_fork]);
	pthread_mutex_unlock(&args->forks[phil->left_fork]);
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
		if (check_cycle(args, phil))
			break ;
		take_forks(args, phil);
		eat(args, phil);
	}
	return (NULL);
}
