/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:34:08 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/26 15:32:48 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_phil(t_arg *args)
{
	int	i;

	i = 0;
	args->phils = malloc(sizeof(struct s_phil) * args->num_phil);
	if (NULL == args->phils)
		return (ft_terror("Memory allocation for philosophers failed"));
	while (i < args->num_phil)
	{
		args->phils[i].ph_id = i;
		args->phils[i].count = 0;
		args->phils[i].startsim = 0;
		args->phils[i].last_eat = 0;
		args->phils[i].left_fork = i;
		args->phils[i].right_fork = (i + 1) % args->num_phil;
		args->phils[i].args = args;
		i++;
	}
	return (0);
}

static int	init_mutex(t_arg *args)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&args->get_write, NULL))
		return (ft_terror("Mutex initialization failed"));
	if (pthread_mutex_init(&args->access, NULL))
		return (ft_terror("Mutex initialization failed"));
	args->forks = malloc(sizeof(pthread_mutex_t) * args->num_phil);
	args->state = malloc(sizeof(int) * args->num_phil);
	if (NULL == args->forks || NULL == args->state)
		return (ft_terror("Memory allocation failed"));
	while (i < args->num_phil)
	{
		if (pthread_mutex_init(&args->forks[i], NULL))
			return (ft_terror("Mutex initialization failed"));
		args->state[i] = 1;
		i++;
	}
	if (pthread_mutex_init(&args->chopchop, NULL))
		return (ft_terror("Mutex initialization failed"));
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
	args->finish = 0;
	if (argc == 6)
		args->num_eat = ft_atoi(argv[5]);
	if (init_mutex(args))
		return (-1);
	if (init_phil(args))
		return (-1);
	return (0);
}
