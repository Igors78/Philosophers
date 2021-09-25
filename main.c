/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:58:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/25 10:12:15 by ioleinik         ###   ########.fr       */
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
	t_arg	args;

	if (check_contract(&args, argc, argv))
		return (-1);
	return (0);
}
