/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:56:01 by agaygisi          #+#    #+#             */
/*   Updated: 2023/09/01 21:56:04 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_isdigit(int c) {
  if ((c >= '0' && c <= '9') || c == '+' || c == '-')
    return (1);
  else
    return (0);
}

int check_num(char *str) {
  int i;

  i = 0;
  while (str[i] != '\0') {
    if (!ft_isdigit(str[i])) {
      return (0);
    }
    i++;
  }
  return (1);
}

int int_limit_check(int argc, char **argv) {
  if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 1) {
    print_error(1);
    return (1);
  }
  if (ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1) {
    print_error(1);
    return (1);
  }
  if (argc == 6 && ft_atoi(argv[5]) < 0) {
    print_error(1);
    return (1);
  }
  return (0);
}

void print_error(int error) {
  if (error == 0) {
    printf("Wrong usage\n");
    printf("./philo number_of_philosophers time_to_die time_to_eat ");
    printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
  }
  if (error == 1) {
    printf("Wrong usage\n");
    printf("Arguments must be positive numbers\n");
  }
  if (error == 2) {
    printf("Wrong usage\n");
    printf("There can't be more than 200 philosophers\n");
  }
}

int error_check(int argc, char *argv[]) {
  if (argc != 5 && argc != 6) {
    print_error(0);
    return (1);
  }
  if (!check_num(argv[1]) || !check_num(argv[2]) || !check_num(argv[3]) ||
      !check_num(argv[4])) {
    print_error(1);
    return (1);
  }
  if (argc == 6 && !check_num(argv[5])) {
    print_error(0);
    return (1);
  }
  if (int_limit_check(argc, argv))
    return (1);
  if (ft_atoi(argv[1]) > 200) {
    print_error(2);
    return (1);
  }
  return (0);
}
