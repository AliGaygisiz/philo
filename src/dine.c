/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:55:53 by agaygisi          #+#    #+#             */
/*   Updated: 2023/09/01 21:55:55 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void eat(t_philo *philo) {
  t_data *data;

  data = philo->data;
  pthread_mutex_lock(&(data->forks[philo->fork_l]));
  safe_print(data, philo->id, "has taken a fork");
  pthread_mutex_lock(&(data->forks[philo->fork_r]));
  safe_print(data, philo->id, "has taken a fork");
  pthread_mutex_lock(&(data->meal_lock));
  safe_print(data, philo->id, "is eating");
  pthread_mutex_lock(&(data->gct_lock));
  philo->last_eat = gct();
  pthread_mutex_unlock(&(data->gct_lock));
  pthread_mutex_unlock(&(data->meal_lock));
  ft_sleep(data->tt_eat, data);
  pthread_mutex_unlock(&(data->forks[philo->fork_l]));
  pthread_mutex_unlock(&(data->forks[philo->fork_r]));
  pthread_mutex_lock(&(data->meal_count_lock));
  philo->eat_num += 1;
  pthread_mutex_unlock(&(data->meal_count_lock));
}

void *philo_thread(void *empty_philo) {
  t_philo *philo;
  t_data *data;

  philo = (t_philo *)empty_philo;
  data = philo->data;
  if (philo->id % 2 == 0)
    ft_sleep(data->philo_num / 20 + 3, data);
  while (!get_dead(data)) {
    eat(philo);
    if (data->eat_num != -1 && philo->eat_num >= data->eat_num)
      break;
    safe_print(data, philo->id, "is sleeping");
    ft_sleep(data->tt_sleep, data);
    safe_print(data, philo->id, "is thinking");
  }
  return (NULL);
}

void destroy(t_data *data, t_philo *philo) {
  int i;

  i = 0;
  while (i < data->philo_num) {
    pthread_join(philo[i].thread, NULL);
    i++;
  }
  i = 0;
  while (i < data->philo_num) {
    pthread_mutex_destroy(&(data->forks[i]));
    i++;
  }
  pthread_mutex_destroy(&(data->print_lock));
  pthread_mutex_destroy(&(data->meal_lock));
}

void any_dead(t_data *data, t_philo *philo) {
  int i;

  while (!(data->all_eat)) {
    i = -1;
    while (++i < data->philo_num && !(data->dead)) {
      pthread_mutex_lock(&(data->meal_lock));
      if (gct() - philo[i].last_eat > data->tt_die) {
        safe_print(data, philo[i].id, "died");
        kill_philo(data);
      }
      pthread_mutex_unlock(&(data->meal_lock));
      usleep(50);
    }
    if (get_dead(data))
      break;
    i = 0;
    while (data->eat_num != -1 && i < data->philo_num &&
           get_eat_count(data, philo[i]) >= data->eat_num)
      i++;
    if (i == data->philo_num)
      data->all_eat = 1;
  }
}

int dine(t_data *data) {
  t_philo *philo;
  int i;

  i = 0;
  philo = data->philos;
  data->epoch = gct();
  while (i < data->philo_num) {
    pthread_create(&(philo[i].thread), NULL, philo_thread, &(philo[i]));
    pthread_mutex_lock(&(data->gct_lock));
    philo[i].last_eat = gct();
    pthread_mutex_unlock(&(data->gct_lock));
    i++;
  }
  any_dead(data, philo);
  destroy(data, philo);
  return (0);
}
