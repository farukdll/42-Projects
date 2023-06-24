#include "philo.h"

void	ft_philo_eat(t_philo *philo)
{
	if (ft_philo_check(philo))
		return ;
	pthread_mutex_lock(philo->left_fork_mutex);
	pthread_mutex_lock(philo->right_fork_mutex);
	ft_philo_print(philo, "has taken a fork", 0);
	ft_philo_print(philo, "has taken a fork ", 0);
	ft_philo_print(philo, "is eating", 0);
	pthread_mutex_lock(philo->death);
	philo->total_eaten++;
	philo->last_eat_time = ft_get_time();
	pthread_mutex_unlock(philo->death);
	ft_philo_wait(philo, philo->eat_time);
	if (ft_philo_check(philo))
		return ;
}

void	ft_philo_sleep(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	if (ft_philo_check(philo))
		return ;
	ft_philo_print(philo, "is sleeping", 0);
	ft_philo_wait(philo, philo->sleep_time);
}

void	ft_philo_think(t_philo *philo)
{
	if (ft_philo_check(philo))
		return ;
	ft_philo_print(philo, "is thinking", 0);
}

void	*ft_life_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->total_philo == 1 && !ft_philo_check(philo))
	{
		if (pthread_mutex_lock(philo->left_fork_mutex))
			return (NULL);
		ft_philo_print(philo, " has taken a fork", 0);
		while (!ft_philo_check(philo))
		{	
		}
		pthread_mutex_unlock(philo->left_fork_mutex);
	}
	else
	{
		while (1)
		{
			if (ft_philo_check(philo))
				break ;
			ft_philo_eat(philo);
			ft_philo_sleep(philo);
			ft_philo_think(philo);
		}
	}
	return (NULL);
}
