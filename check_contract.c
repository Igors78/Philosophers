/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:34:08 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/21 21:33:01 by ioleinik         ###   ########.fr       */
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

static int	alloc_phils(t_data data)
{
	int	i;

	i = 0;
	data->phil = (t_phil *)malloc(sizeof(struct s_phil) * (data->num_phil));
	if (NULL == data->phil)
		return (-1);
	while (i < data->num_phil)
	{
		data->phil[i].time_die = data->time_die;
		data->phil[i].time_eat = data->time_eat + i;
		data->phil[i].time_sleep = data->time_sleep;
		data->phil[i].num_eat = data->num_eat;
		printf("%d phil %d number\n", i, data->phil[i].time_die);
		printf("%d phil %d number\n", i, data->phil[i].time_eat);
		printf("%d phil %d number\n", i, data->phil[i].time_sleep);
		printf("%d phil %d number\n", i, data->phil[i].num_eat);
		i++;
	}
	return (0);
}

static int	init_data(t_data data, int argc, char **argv)
{
	data->num_phil = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->num_eat = 0;
	if (argc == 6)
		data->num_eat = ft_atoi(argv[5]);
	data->phil = NULL;
	if (alloc_phils(data))
		return (-1);
	return (0);
}

int	check_contract(int argc, char **argv, t_data data)
{
	if (argc != 5 && argc != 6)
		return (-1);
	if (init_data(data, argc, argv))
		return (-1);
	if (data->num_phil <= 0 || data->time_die <= 0 || data->time_eat <= 0
		|| data->time_sleep <= 0)
		return (-1);
	if (argc == 6 && data->num_eat <= 0)
		return (-1);
	return (0);
}
