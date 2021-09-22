/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:58:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/22 10:44:43 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_t	*th;
	t_phil		*philos;
	int			phil_num;
	int			i;

	i = 0;
	if (check_contract(argc, argv))
		return (-1);
	phil_num = ft_atoi(argv[1]);
	philos = NULL;
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
	if (init_philos(philos, argc, argv))
		return (-1);
	gettimeofday(&philos[0]->stamp, NULL);
	printf("seconds : %ld\nmicro seconds : %ld\n",
		philos[0]->stamp.tv_sec, philos[0]->stamp.tv_usec);
	th = NULL;
	th = (pthread_t *)malloc(sizeof(pthread_t) * phil_num);
	if (NULL == th)
		return (-1);
	return (0);
}
