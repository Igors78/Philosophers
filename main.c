/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:58:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/22 16:49:18 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_th(t_phil *philos, int i)
{
	pthread_t		*th;
	t_arg			args;
	int				n;

	n = 0;
	args = (t_arg)malloc(sizeof(struct s_arg));
	th = (pthread_t *)malloc(sizeof(pthread_t) * i);
	if (NULL == args || NULL == th)
		return (-1);
	args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * i);
	if (NULL == args->forks)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_phil		*philos;
	int			phil_num;
	int			i;

	i = 0;
	if (check_contract(argc, argv))
		return (-1);
	phil_num = ft_atoi(argv[1]);
	philos = (t_phil *)malloc(sizeof(t_phil) * phil_num);
	if (NULL == philos)
		return (-1);
	while (i < phil_num)
	{
		philos[i] = (t_phil)malloc(sizeof(struct s_phil));
		if (NULL == philos[i])
			return (-1);
		i++;
	}
	if (init_philos(philos, argc, argv) || create_th(philos, phil_num))
		return (-1);
	gettimeofday(&philos[0]->start, NULL);
	printf("seconds : %ld\nmicro seconds : %ld\n",
		philos[0]->start.tv_sec, philos[0]->start.tv_usec);
	gettimeofday(&philos[0]->end, NULL);
	printf("seconds : %ld\nmicro seconds : %ld\n",
		philos[0]->end.tv_sec, philos[0]->end.tv_usec);
	return (0);
}
