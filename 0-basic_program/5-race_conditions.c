/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-race_conditions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:13:06 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 15:21:52 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define N_TH 2 // N_TH stands for Number of threads

int counter; 
//this is a shared counter between all threads

//at every thread the variable got incremented 10000 times
//normally the counter should be 20000
//but it is not the case because of something called race conditions

void	*routine()
{
	int	i;

	i = 0;
	while (i++ < 10000)
		counter++;
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
