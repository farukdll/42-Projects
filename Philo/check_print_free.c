#include "philo.h"

int	ft_philo_check(t_philo *philo)
{
	if (philo->total_eaten == philo->must_eat)
		return (1);
	pthread_mutex_lock(philo->death);
	if (*philo->check_dead)
	{
		pthread_mutex_unlock(philo->death);
		return (1);
	}
	pthread_mutex_unlock(philo->death);
	if (ft_get_time() - philo->last_eat_time > \
		philo->die_time)
	{
		ft_philo_print(philo, "died", 1);
		return (1);
	}
	return (0);
}

int	ft_philo_wait(t_philo *philo, t_time wait_time)
{
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < wait_time)
	{
		if (ft_philo_check(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

void	ft_philo_print(t_philo *philo, char *status, int kill)
{
	pthread_mutex_lock(philo->death);
	if (!*philo->check_dead)
	{
		printf ("%llu %d %s\n", (ft_get_time() - philo->start_time), \
		philo->id + 1, status);
		if (kill)
			*philo->check_dead = 1;
	}
	pthread_mutex_unlock(philo->death);
	ft_philo_check(philo);
}

void	ft_free(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philo->total_philo)
	{
		pthread_mutex_destroy(philo[i].left_fork_mutex);
		pthread_mutex_destroy(philo[i].right_fork_mutex);
		i++;
	}
	pthread_mutex_destroy(philo->death);
	pthread_mutex_destroy(forks);
	free(death);
	free(philo->check_dead);
	free(philo);
}
