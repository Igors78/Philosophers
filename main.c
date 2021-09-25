/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:58:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/25 16:13:00 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_th(t_arg *args)
{
	void	*rout_v;
	int		i;

	i = 0;
	args->start = get_time();
	printf("%lu start", args->start);
	while (i < args->num_phil)
	{
		args->phils[i].when_die = get_time();
		rout_v = (void *)&(args->phils[i]);
		if (pthread_create(&(args->phils[i].thread_id), NULL, routine, rout_v))
			return (ft_terror("Thread creation failed"));
		i++;
	}
	i = 0;
	while (i < args->num_phil)
	{
		if (pthread_join((args->phils[i].thread_id), NULL))
			return (ft_terror("Thread joining failed"));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (check_contract(&args, argc, argv))
		return (-1);
	if (create_th(&args))
		return (-1);
	return (0);
}
