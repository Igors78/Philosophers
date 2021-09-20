/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:58:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/20 19:29:12 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_t	*phils;

	if (check_contract(argc, argv, phil) == -1)
		return (1);
	phils = NULL;
	phils = (pthread_t *)malloc(sizeof(pthread_t) * (phil->num_phil));
	if (NULL == phil->phils)
		return (-1);
	return (0);
}
