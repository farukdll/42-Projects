#include "philo.h"

void	ft_philo_init(t_philo *philo, char **av, int ac)
{
	int	*check_dead;
	int	i;

	i = 0;
	check_dead = malloc(sizeof(int));
	*check_dead = 0;
	while (i < ft_atol(av[1]))
	{
		philo[i].id = i;
		philo[i].die_time = ft_atol(av[2]);
		philo[i].eat_time = ft_atol(av[3]);
		philo[i].sleep_time = ft_atol(av[4]);
		if (ac == 6)
			philo[i].must_eat = ft_atol(av[5]);
		else
			philo[i].must_eat = -1;
		philo[i].last_eat_time = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].total_eaten = 0;
		philo[i].total_philo = ft_atol(av[1]);
		philo[i].check_dead = check_dead;
		i++;
	}
}

void	create_init_mutex(t_philo *philo, pthread_mutex_t *forks, \
		pthread_mutex_t *death)
{
	long long	i;

	i = 0;
	while (i < philo->total_philo)
	{
		philo[i].left_fork_mutex = &forks[i];
		philo[i].right_fork_mutex = &forks[(i + 1) % philo->total_philo];
		i++;
	}
	i = 0;
	while (i < philo->total_philo)
	{
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		philo[i].death = death;
		i++;
	}
	pthread_mutex_init(philo->death, NULL);
}

void	ft_distribute_threads(t_philo *philo, char **argv)
{
	int	i;

	i = 0;
	while (i < (ft_atol(argv[1])))
	{
		pthread_create(&philo[i].thread, NULL, &ft_life_philo, &philo[i]);
		i++;
		usleep(100);
	}
	i = 0;
	while (i < (ft_atol(argv[1])))
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	while ((*philo).check_dead == 0)
	{
		ft_philo_check(philo);
	}
}
