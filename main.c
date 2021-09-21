/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:58:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/21 21:01:40 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	//pthread_t	*philos;
	t_data		data;

	data = NULL;
	if (check_contract(argc, argv, data) == -1)
		return (1);
	// philos = NULL;
	// philos = (pthread_t *)malloc(sizeof(pthread_t) * (data->num_phil));
	// if (NULL == philos)
	// 	return (-1);
	return (0);
}
