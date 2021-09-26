/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:59:00 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/26 09:30:54 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define YL		"\033[1;33m"
# define GN		"\033[1;32m"
# define BL		"\033[1;34m"
# define PK		"\033[1;35m"
# define GR		"\033[1;30m"
# define CY		"\033[1;36m"
# define RD		"\033[1;31m"
# define CLR	"\x1b[0m"

typedef struct s_phil
{
	int				ph_id;
	int				count;
	unsigned int	left_fork;
	unsigned int	right_fork;
	long long		last_eat;
	long long		startsim;
	struct s_arg	*args;
	pthread_t		thread_id;
}				t_phil;

typedef struct s_arg
{
	int				num_phil;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				finish;
	long long		start;
	t_phil			*phils;
	pthread_mutex_t	*forks;
	pthread_mutex_t	chopchop;
	pthread_mutex_t	access;
	pthread_mutex_t	get_write;
}				t_arg;

int				check_contract(t_arg *args, int argc, char **argv);
int				ft_atoi(const char *str);
int				ft_terror(char *s);
void			m_print(t_arg *args, char *str, int id);
long long		get_time(void);
void			*routine(void *philosoph);

#endif