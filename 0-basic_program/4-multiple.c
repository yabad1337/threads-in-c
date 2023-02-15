/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-multiple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:00 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 15:09:28 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define N_TH 10 // N_TH stands for Number of threads

// now we're going to create 10 threads using while loop

void	*routine()
{
	printf("Thread Begins\n");
	sleep(2);
	printf("Thread Ends\n");
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	th[N_TH];
	int			i;

	i = 0;
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
	return (0);
}

// in this program we created two while loops so we can use the power of threads
// which is parallelism, because we don't want the while loop to execute
// one thread at time, we want them all at once.
