/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:34:08 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/23 12:54:31 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
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

void	init_philos(t_phil *philos, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].th_nbr = i;
		philos[i].num_phil = ft_atoi(argv[1]);
		philos[i].time_die = ft_atoi(argv[2]);
		philos[i].time_eat = ft_atoi(argv[3]);
		philos[i].time_sleep = ft_atoi(argv[4]);
		philos[i].num_eat = 0;
		if (argc == 6)
			philos[i].num_eat = ft_atoi(argv[5]);
		i++;
	}
}

int	init_forks(t_arg args, int phil_num)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&args->access, NULL))
		return (-1);
	while (i < phil_num)
	{
		if (pthread_mutex_init(&args->forks[i], NULL))
			return (-1);
		i++;
	}
	return (0);
}

int	check_contract(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (-1);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1
		|| ft_atoi(argv[4]) < 1)
		return (-1);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (-1);
	return (0);
}
