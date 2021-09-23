/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:59:00 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/23 20:42:05 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define YELLOW	"\033[1;33m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define GRAY	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RED	"\033[1;31m"
# define RESET	"\x1b[0m"

# define THINKING	0
# define HUNGRY		1
# define EATING		2

typedef struct s_phil
{
	int				th_nbr;
	int				num_phil;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	struct timeval	start;
	struct timeval	end;
}				t_phil;

typedef struct s_arg
{
	t_phil			phil;
	pthread_mutex_t	*forks;
	pthread_mutex_t	access;
}				*t_arg;

int		check_contract(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_terror(char *s);
void	init_philos(t_phil *philos, int argc, char **argv);
int		init_forks(t_arg args, int phil_num);
void	*routine(void *arg);

#endif