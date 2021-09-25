/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:33:13 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/25 12:50:51 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philosoph)
{
	t_arg	*args;
	t_phil	*phil;

	phil = (t_phil *)philosoph;
	args = phil->args;
	printf("Th id %d\n", phil->ph_id);
	printf("Arg copy id %d\n", args->num_phil);
	return (NULL);
}
