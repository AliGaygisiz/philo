/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:03:23 by agaygisi          #+#    #+#             */
/*   Updated: 2023/09/01 22:03:28 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *single_philo(void *empty_philo) {
  t_philo *philo;
  t_data *data;

  philo = (t_philo *)empty_philo;
  data = philo->data;
  pthread_mutex_init(&data->forks[0], NULL);
  while (!(data->dead)) {
    pthread_mutex_lock(&(data->forks[philo->fork_l]));
    safe_print(data, philo->id, "has taken a fork");
    ft_sleep(data->tt_die, data);
    safe_print(data, philo->id, "died");
    data->dead = 1;
    pthread_mutex_unlock(&(data->forks[philo->fork_l]));
    pthread_mutex_destroy(&(data->forks[0]));
    break;
  }
  return (NULL);
}
