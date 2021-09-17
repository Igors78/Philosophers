/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:34:08 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/17 13:37:01 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] != '\0') && (str[i] == ' ' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483648 || res < -2147483649)
			return (0);
		i++;
	}
	return (((int)res * sign));
}

static int	alloc_phils(t_data phil)
{
	phil->phils = (pthread_t *)malloc(sizeof(pthread_t) * (phil->num_phil));
	if (NULL == phil->phils)
		return (-1);
	return (0);
}

int	check_contract(int argc, char **argv, t_data phil)
{
	phil = (t_data)malloc(sizeof(struct s_data));
	if (NULL == phil)
		return (-1);
	if (argc != 5 && argc != 6)
		return (-1);
	phil->num_phil = ft_atoi(argv[1]);
	phil->time_die = ft_atoi(argv[2]);
	phil->time_eat = ft_atoi(argv[3]);
	phil->time_sleep = ft_atoi(argv[4]);
	phil->num_eat = 0;
	if (argc == 6)
		phil->num_eat = ft_atoi(argv[5]);
	if (phil->num_phil <= 0 || phil->time_die <= 0 || phil->time_eat <= 0
		|| phil->time_sleep <= 0)
		return (-1);
	if (argc == 6 && phil->num_eat <= 0)
		return (-1);
	phil->phils = NULL;
	if (alloc_phils(phil) == -1)
		return (-1);
	return (0);
}
