/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9-threads_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:22:28 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 17:57:01 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define TH 10
//problem : create 10 threads, each taking a unique prime from the primes array
//			and print it on the screen

int	primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void	*routine(void *arg)
{
	int	index;

	index = *(int *)arg;
	printf("%d ", primes[index]);
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	th[TH];
	int			i;
	int			*a;

	i = 0;
	while (i < TH)
	{
		a = (int *)malloc(sizeof(int));
		if (!a)
			return (0);
		*a = i;
		if (pthread_create(th + i, NULL, &routine, a))
			return (1);
		i++;
	}
	i = 0;
	while (i < TH)
	{
		if (pthread_join(th[i], NULL))
			return (2);
		i++;
	}
	return (0);
}
