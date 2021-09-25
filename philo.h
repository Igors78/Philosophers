/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:59:00 by ioleinik          #+#    #+#             */
/*   Updated: 2021/09/25 12:42:25 by ioleinik         ###   ########.fr       */
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
	int				ph_id;
	unsigned int	left_fork;
	unsigned int	right_fork;
	unsigned long	when_die;
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
	unsigned long	start;
	t_phil			*phils;
	pthread_mutex_t	*forks;
	pthread_mutex_t	access;
	pthread_mutex_t	get_write;
}				t_arg;

int				check_contract(t_arg *args, int argc, char **argv);
int				ft_atoi(const char *str);
int				ft_terror(char *s);
unsigned long	get_time(void);
void			*routine(void *philosoph);

#endif