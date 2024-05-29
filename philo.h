/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:55:34 by agaygisi          #+#    #+#             */
/*   Updated: 2023/09/01 21:55:36 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

struct s_data;

typedef struct s_philo {
  int id;
  int eat_num;
  int fork_l;
  int fork_r;
  long long last_eat;
  struct s_data *data;
  pthread_t thread;
} t_philo;

typedef struct s_data {
  int philo_num;
  int tt_die;
  int tt_eat;
  int tt_sleep;
  int eat_num;
  int dead;
  int total_eat;
  int all_eat;
  long long epoch;
  pthread_mutex_t meal_lock;
  pthread_mutex_t print_lock;
  pthread_mutex_t gct_lock;
  pthread_mutex_t dead_lock;
  pthread_mutex_t meal_count_lock;
  pthread_mutex_t forks[200];
  t_philo philos[200];
} t_data;

int ft_atoi(const char *str);
int ft_isdigit(int c);
int check_num(char *str);
void error_message(void);
int error_check(int argc, char *argv[]);
void init_mutex(t_data *data);
void init_philos(t_data *data);
int init(t_data *data, char **argv);
long long gct(void);
long long td(long long prev, long long now);
void ft_sleep(long long time, t_data *data);
void safe_print(t_data *data, int id, char *str);
void eat(t_philo *philo);
void *philo_thread(void *empty_philo);
void destroy(t_data *data, t_philo *philo);
void any_dead(t_data *data, t_philo *philo);
int dine(t_data *data);
void *single_philo(void *empty_philo);
int get_dead(t_data *data);
void kill_philo(t_data *data);
int get_eat_count(t_data *data, t_philo philo);
void print_error(int error);

#endif
