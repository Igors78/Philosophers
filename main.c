/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:58:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/23 12:55:31 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_th(t_arg args, t_phil *philos, int i)
{
	pthread_t		*th;
	int				n;

	n = 0;
	th = (pthread_t *)malloc(sizeof(pthread_t) * i);
	if (NULL == th)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_phil		*philos;
	t_arg		args;
	int			phil_num;

	if (check_contract(argc, argv))
		return (-1);
	phil_num = ft_atoi(argv[1]);
	args = (t_arg *)malloc(sizeof(struct s_arg));
	philos = (t_phil *)malloc(sizeof(struct s_phil) * phil_num);
	if (NULL == args || NULL == philos)
		return (-1);
	init_philos(philos, argc, argv);
	if (init_forks(args, phil_num) || create_th(args, philos, phil_num))
		return (-1);
	return (0);
}
