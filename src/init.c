/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:56:10 by agaygisi          #+#    #+#             */
/*   Updated: 2023/09/01 21:56:11 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void init_mutex(t_data *data) {
  int i;

  i = data->philo_num;
  while (--i >= 0)
    pthread_mutex_init(&data->forks[i], NULL);
  pthread_mutex_init(&data->print_lock, NULL);
  pthread_mutex_init(&data->meal_lock, NULL);
  pthread_mutex_init(&data->gct_lock, NULL);
  pthread_mutex_init(&data->dead_lock, NULL);
  pthread_mutex_init(&data->meal_count_lock, NULL);
  return;
}

void init_philos(t_data *data) {
  int i;

  i = data->philo_num;
  while (--i >= 0) {
    data->philos[i].id = i;
    data->philos[i].data = data;
    data->philos[i].eat_num = 0;
    data->philos[i].last_eat = 0;
    data->philos[i].fork_l = i;
    data->philos[i].fork_r = (i + 1) % data->philo_num;
  }
  return;
}

int init(t_data *data, char **argv) {
  data->philo_num = ft_atoi(argv[1]);
  data->tt_die = ft_atoi(argv[2]);
  data->tt_eat = ft_atoi(argv[3]);
  data->tt_sleep = ft_atoi(argv[4]);
  data->dead = 0;
  data->eat_num = -1;
  if (data->philo_num < 2 || data->tt_die < 0 || data->tt_eat < 0 ||
      data->tt_sleep < 0)
    return (1);
  if (argv[5]) {
    data->eat_num = ft_atoi(argv[5]);
    if (data->eat_num < 0)
      return (1);
  }
  init_mutex(data);
  init_philos(data);
  return (0);
}
