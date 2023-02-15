/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7-mutex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:13:06 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 16:00:38 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define N_TH 2 // N_TH stands for Number of threads

int counter; 
//this is a shared counter between all threads

//we can fix this race condition situation by creating a lock

pthread_mutex_t	lock;

void	*routine()
{
	int	i;

	i = 0;
	pthread_mutex_lock(&lock);
	while (i++ < 10000)
		counter++;
	pthread_mutex_unlock(&lock);
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	th[N_TH];
	int			i;

	i = 0;
	pthread_mutex_init(&lock, NULL);
	while (i < N_TH)
	{
		if (pthread_create(th + i, NULL, &routine, NULL))
		{
			printf("Error while creating a thread\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < N_TH)
	{
		if (pthread_join(th[i], NULL))
			return (2);
		i++;
	}
	printf("counter : %d\n", counter);
	pthread_mutex_destroy(&lock);
	return (0);
}

// by creating a mutex lock we solved the problem
