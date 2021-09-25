/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:34:08 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/25 11:07:27 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_phil(t_arg *args)
{
	
}

static int	init_mutex(t_arg *args)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&args->access, NULL))
		return (ft_terror("Mutex initialization failed"));
	if (pthread_mutex_init(&args->get_write, NULL))
		return (ft_terror("Mutex initialization failed"));
	args->forks = malloc(sizeof(pthread_mutex_t) * args->num_phil);
	if (NULL == args->forks)
		return (ft_terror("Memory allocation failed"));
	while (i < args->num_phil)
	{
		if (pthread_mutex_init(&args->forks[i], NULL))
			return (ft_terror("Mutex initialization failed"));
		i++;
	}
	return (0);
}

int	check_contract(t_arg *args, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ft_terror("Argument error"));
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 60
		|| ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (ft_terror("Incorrect arguments"));
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (ft_terror("Incorrect arguments"));
	args->num_phil = ft_atoi(argv[1]);
	args->time_die = ft_atoi(argv[2]);
	args->time_eat = ft_atoi(argv[3]);
	args->time_sleep = ft_atoi(argv[4]);
	args->num_eat = 0;
	if (argc == 6)
		args->num_eat = ft_atoi(argv[5]);
	if (init_mutex(args))
		return (-1);
	if (init_phil(args))
		return (-1);
	return (0);
}
