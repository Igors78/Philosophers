/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:39:15 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/25 16:08:53 by ioleinik         ###   ########.fr       */
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

int	ft_terror(char *s)
{
	printf("%s\n", s);
	return (-1);
}

unsigned long	get_time(void)
{
	struct timeval	timing;
	unsigned long	time;

	gettimeofday(&timing, NULL);
	time = (timing.tv_sec * 1000);
	return (time);
}

void	m_print(t_arg *args, char *str, int id)
{
	pthread_mutex_lock(&(args->get_write));
	if (!(args->finish))
	{
		if (id % 6 == 0)
			printf(YL "%lu %d %s\n" CLR, get_time() - args->start, id + 1, str);
		else if (id % 6 == 1)
			printf(GN "%lu %d %s\n" CLR, get_time() - args->start, id + 1, str);
		else if (id % 6 == 2)
			printf(BL "%lu %d %s\n" CLR, get_time() - args->start, id + 1, str);
		else if (id % 6 == 3)
			printf(PK "%lu %d %s\n" CLR, get_time() - args->start, id + 1, str);
		else if (id % 6 == 4)
			printf(GR "%lu %d %s\n" CLR, get_time() - args->start, id + 1, str);
		else if (id % 6 == 5)
			printf(CY "%lu %d %s\n" CLR, get_time() - args->start, id + 1, str);
		else
			printf(RD "%lu %d %s\n" CLR, get_time() - args->start, id + 1, str);
	}
	pthread_mutex_unlock(&(args->get_write));
	return ;
}
