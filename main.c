/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:58:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/21 21:33:24 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_t	*philos;
	t_data		data;

	data = NULL;
	data = (t_data)malloc(sizeof(struct s_data));
	if (NULL == data)
		return (-1);
	if (check_contract(argc, argv, data) == -1)
		return (1);
	philos = NULL;
	printf("%d phils\n", data->phil[2].time_eat);
	philos = (pthread_t *)malloc(sizeof(pthread_t) * (data->num_phil));
	if (NULL == philos)
		return (-1);
	return (0);
}
