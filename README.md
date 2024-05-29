# Dining Philosophers Problem

Implementation of the [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) in C using threads.

### Usage
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
> `number of times each philosopher must eat` is optional. If provided, the program should stop when each philosopher has eaten that many times. Otherwise, it will continue until one philosopher dies.
