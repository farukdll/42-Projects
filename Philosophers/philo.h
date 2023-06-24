#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define ERROR -1
# define INT_MAX 2147483647

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				must_eat;
	int				total_philo;
	int				total_eaten;
	int				*check_dead;
	t_time			die_time;
	t_time			eat_time;
	t_time			sleep_time;
	t_time			start_time;
	t_time			last_eat_time;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
}	t_philo;

t_time				ft_get_time(void);
int					main(int argc, char **argv);
int					ft_argcheck(int argc, char **argv);
unsigned long long	ft_get_time(void);
long long			ft_atol(const char *str);
void				create_init_mutex(t_philo *philo, pthread_mutex_t *forks, \
					pthread_mutex_t *death);
int					ft_philo_wait(t_philo *philo, unsigned long long wait_time);
void				ft_philo_init(t_philo *philo, char **av, int ac);
int					ft_philo_check(t_philo *philo);
void				ft_philo_print(t_philo *philo, char *status, int kill);
void				ft_free(t_philo *philo, pthread_mutex_t *forks, \
pthread_mutex_t *death);
void				ft_distribute_threads(t_philo *philo, char **argv);
void				*ft_life_philo(void *args);
void				ft_philo_sleep(t_philo *philo);
void				ft_philo_think(t_philo *philo);
void				ft_philo_eat(t_philo *philo);
#endif
