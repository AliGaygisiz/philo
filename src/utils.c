/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:56:16 by agaygisi          #+#    #+#             */
/*   Updated: 2023/09/01 21:56:18 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_atoi(const char *str) {
  int i;
  int sign;
  long numb;

  i = 0;
  sign = 1;
  numb = 0;
  while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
    i++;
  if (str[i] == '+' || str[i] == '-') {
    if (str[i] == '-')
      sign *= -1;
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9') {
    numb = (str[i] - '0') * sign + (numb * 10);
    if (numb > 2147483647)
      return (-1);
    if (numb < -2147483648)
      return (0);
    i++;
  }
  return ((int)numb);
}

long long gct(void) {
  struct timeval tv;
  long long time;

  gettimeofday(&tv, NULL);
  time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
  return (time);
}

long long td(long long prev, long long now) { return (now - prev); }

void ft_sleep(long long time, t_data *data) {
  long long start;

  start = gct();
  while (!get_dead(data) && td(start, gct()) < time)
    usleep(50);
  return;
}

void safe_print(t_data *data, int id, char *str) {
  pthread_mutex_lock(&(data->print_lock));
  if (!get_dead(data)) {
    printf("%lld %d %s\n", gct() - data->epoch, id + 1, str);
  }
  pthread_mutex_unlock(&(data->print_lock));
  return;
}
