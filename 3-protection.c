/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-protection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:00 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 15:00:35 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// now we're going to protect our program

void	*routine()
{
	printf("Thread Begins\n");
	sleep(2);
	printf("Thread Ends\n");
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	t1, t2;

	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL))
		return (2);
	if (pthread_join(t1, NULL))
		return (3);
	if (pthread_join(t2, NULL))
		return (4);
	return (0);
}

// pthread_create and pthread_join returns 0 on success and non-zero on Failure
// but wait what if we want to create multiple threads ?
