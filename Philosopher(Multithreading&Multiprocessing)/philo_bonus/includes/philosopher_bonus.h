/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:13:24 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 11:11:34 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>

enum e_PID
{
	FAIL = -1,
	CHILD = 0,
	PARENT = 1
};

# define DEAD 0

typedef struct s_info
{
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			min_dine;
	int			dine_cnt;
	int			head_cnt;
	int			philo_num;
	long long	t_last_meal;
	long long	t_start;
	char		**sem_names;
	pthread_t	tid;
	pid_t		*pid;
}	t_info;

typedef struct s_sem
{
	sem_t	**meal_update_sem;
	sem_t	*meal_finished_sem;
	sem_t	*fork_sem;
	sem_t	*fork_auth_sem;
	sem_t	*end_sem;
	sem_t	*print_sem;
}	t_sem;

typedef struct s_com
{
	t_info	*info;
	t_sem	*semaphores;
	int		philo_num;
}	t_com;

/* ===============./main=============== */

void		kill_all_process(t_info *info);
void		exit_program(t_info *info, t_sem *semaphores, int exit_value);
void		free_info(t_info *info);
t_info		*set_info(int argc, char *argv[]);
int			set_program_argument(t_info *info, int argc, char *argv[]);
int			make_sem_names(char **sem_names, int head_cnt);

/* ===============./monitoring=============== */

void		make_monitor(t_info *info, t_sem *semaphores);
void		*monitor_death(void *thread_arg);
int			is_dead(t_info *info);

/* ===============./philosopher=============== */

void		make_philosophers(t_info *info, t_sem *semaphores);
void		philo_eat(t_info *info, t_sem *semaphores);
void		get_forks(t_info *info, t_sem *semaphores);
void		grab_fork(t_info *info, t_sem *semaphores);
void		dine(t_info *info, t_sem *semaphores);
void		put_fork(t_sem *semaphores);
void		start_routine(t_info *info, t_sem *semaphores, int philo_num);
void		set_thread_arg(t_com *thread_arg, t_info *info, \
			t_sem *semaphores, int philo_num);
void		end_dining(t_info *info, t_sem *semaphores, int philo_num);
void		philo_sleep(t_info *info, t_sem *semaphores);
void		philo_think(t_info *info, t_sem *semaphores);

/* ===============./semaphore=============== */

void		unlink_semaphores(char **sem_names, int head_cnt);
void		clear_semaphores(t_sem *semaphores, char **sem_names, int head_cnt);
void		close_unlink_semaphore(sem_t *semaphore, char *name);
void		make_semaphores(t_info *info, t_sem *sems);
void		open_meal_update_sem(t_info *info, t_sem *sems);
void		clear_unfailed_sem(t_info *info, t_sem *semaphores);
void		increase_semaphores(t_info *info, t_sem *semaphores);

/* ===============./utils=============== */

char		*ft_strfjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);
int			get_len(int n);
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
void		count_time(t_info *info, long duration, long long start_time);
long long	get_time(void);
void		print_msg(t_info *info, t_sem *semaphores, char *action);

#endif
