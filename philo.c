/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:55:25 by agaygisi          #+#    #+#             */
/*   Updated: 2023/09/01 21:55:27 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[]) {
  t_data data;
  t_philo *philo;

  if ((error_check(argc, argv)) || (argc == 6 && ft_atoi(argv[5]) == 0))
    return (1);
  if (ft_atoi(argv[1]) == 1) {
    data.philo_num = ft_atoi(argv[1]);
    data.tt_die = ft_atoi(argv[2]);
    data.tt_eat = ft_atoi(argv[3]);
    data.tt_sleep = ft_atoi(argv[4]);
    data.dead = 0;
    data.epoch = gct();
    philo = malloc(sizeof(t_philo));
    philo->id = 0;
    philo->last_eat = gct();
    philo->data = &data;
    philo->fork_l = 0;
    single_philo(philo);
    free(philo);
    return (0);
  }
  init(&data, argv);
  dine(&data);
  return (0);
}
