/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:33:13 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/25 16:11:19 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philosoph)
{
	t_arg	*args;
	t_phil	*phil;

	phil = (t_phil *)philosoph;
	args = phil->args;
	pthread_mutex_lock(&args->access);
	pthread_mutex_lock(&args->forks[phil->left_fork]);
	m_print(args, "has taken a fork", phil->ph_id);
	pthread_mutex_lock(&args->forks[phil->right_fork]);
	m_print(args, "has taken a fork", phil->ph_id);
	pthread_mutex_unlock(&args->access);
	m_print(args, "eating", phil->ph_id);
	usleep(args->time_sleep * 1000);
	pthread_mutex_unlock(&args->forks[phil->right_fork]);
	pthread_mutex_unlock(&args->forks[phil->left_fork]);
	m_print(args, "stopped eating", phil->ph_id);
	return (NULL);
}
