/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:57:48 by agaygisi          #+#    #+#             */
/*   Updated: 2023/09/23 09:57:53 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int get_dead(t_data *data) {
  int is_dead;

  pthread_mutex_lock(&(data->dead_lock));
  is_dead = data->dead;
  pthread_mutex_unlock(&(data->dead_lock));
  return (is_dead);
}

void kill_philo(t_data *data) {
  pthread_mutex_lock(&(data->dead_lock));
  data->dead = 1;
  pthread_mutex_unlock(&(data->dead_lock));
}

int get_eat_count(t_data *data, t_philo philo) {
  int eat_count;

  pthread_mutex_lock(&(data->meal_count_lock));
  eat_count = philo.eat_num;
  pthread_mutex_unlock(&(data->meal_count_lock));
  return (eat_count);
}
