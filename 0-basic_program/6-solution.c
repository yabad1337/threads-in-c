/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-solution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:13:06 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 15:57:13 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define N_TH 2 // N_TH stands for Number of threads

int counter; 
//this is a shared counter between all threads

//we can fix this race condition situation by creating a lock

int	lock;

void	*routine()
{
	int	i;

	if (lock == 1)
		//lock equals 1 before assiging 1 to it this can mean one thing
		//another thread is trying to execute while the other isn't finished
		//yet, so we need to tell it to wait until the other is finished
		//execution
	lock = 1;
	i = 0;
	while (i++ < 10000)
		counter++;
	lock = 0;
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
	printf("counter : %d\n", counter);
	return (0);
}
