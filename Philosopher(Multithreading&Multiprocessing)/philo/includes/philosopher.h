/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:13:24 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 00:55:57 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>

typedef struct s_info
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	*end_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	ready_mutex;
	pthread_mutex_t	err_mutex;
	long long		start_time;
	long long		*meal_taken;
	long long		*t_last_meal;
	int				*is_end;
	int				err;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				min_dine;
	int				head_cnt;
}	t_info;

typedef struct s_phil
{
	pthread_t		id;
	t_info			*info;
	int				num;
}	t_phil;

/* ===============./philosopher=============== */

t_phil		**make_philosophers(t_info *info);
t_phil		*birth(t_info *info, int idx);
int			philo_eat(t_phil *philo);
int			philo_sleep(t_phil *philo);
int			philo_think(t_phil *philo);
void		update_meal_information(t_phil *philo, long long action_time);
void		*routine(void *philosopher);
void		set_start_time(t_phil *philo);
int			is_err(t_phil *philo);

/* ===============./utils=============== */

int			ft_atoi(const char *str);
void		count_time(long long duration, long long start_time);
long long	get_time(void);
int			print_msg(t_phil *philo, char *action);
int			i_am_dead(t_phil *philo);

/* ===============./clean=============== */

void		terminate_program(t_phil **philo_list, t_info *info, int idx);
void		clean_program(t_phil **philo_list, t_info *info, int idx);
void		freedom_to_philosophers(t_phil **philo_list, int idx);
void		free_info(t_info *info);

/* ===============./mutex=============== */

int			make_fork_mutex(t_info *info, int idx);
int			make_meal_mutex(t_info *info, int idx);
int			make_end_mutex(t_info *info, int idx);
long long	grab_fork(t_phil *philo, t_info *info);
long long	lock_fork(t_phil *philo, t_info *info, \
					int first_fork, int second_fork);
void		unlock_fork(t_phil *philo, t_info *info);
int			grab_first_fork(t_phil *philo, t_info *info, int first_fork);
long long	grab_second_fork(t_phil *philo, t_info *info, \
	int first_fork, int second_fork);
int			is_one_fork(t_phil *philo, int right_fork, int left_fork);
void		destroy_mutex(t_info *info, int idx);
void		destroy_mutex_failed_by_meal(t_info *info, int idx);
void		destroy_mutex_failed_by_end(t_info *info, int idx);

/* ===============./monitoring=============== */

int			make_monitor_thread(t_phil **philo_list, t_info *info, \
								pthread_t *monitor_id);
void		*monitor_philosopher(void *info);
int			is_over(t_info *info, long long t_now);
void		kill_all_philosopher(t_info *info);
void		print_died_msg(t_info *info, long long t_now, int idx);

/* ===============./main=============== */

t_info		*set_info(int argc, char *argv[]);
int			set_program_argument(t_info *info, int argc, char *argv[]);
int			allocate_space(t_info *info);
int			initiate_mutex(t_info *info);
void		manage_thread(t_phil **philo_list, t_info *info, \
			pthread_t monitor_id);

#endif
