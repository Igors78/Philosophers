/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:58:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/26 16:30:48 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_th(t_arg *args)
{
	void	*rout_v;
	int		i;

	i = 0;
	args->start = get_time();
	while (i < args->num_phil)
	{
		args->phils[i].startsim = get_time();
		rout_v = (void *)&(args->phils[i]);
		if (pthread_create(&(args->phils[i].thread_id), NULL, routine, rout_v))
			return (ft_terror("Thread creation failed"));
		i++;
	}
	i = 0;
	usleep(1000);
	while (i < args->num_phil)
	{
		if (pthread_join((args->phils[i].thread_id), NULL))
			return (ft_terror("Thread joining failed"));
		i++;
	}
	return (0);
}

static void	clean_up(t_arg *args)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&args->get_write);
	pthread_mutex_destroy(&args->access);
	pthread_mutex_destroy(&args->chopchop);
	while (i < args->num_phil)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	free(args->forks);
	free(args->state);
	free(args->phils);
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (check_contract(&args, argc, argv))
		return (-1);
	if (create_th(&args))
		return (-1);
	clean_up(&args);
	return (0);
}
