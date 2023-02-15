/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-two_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:00 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 14:40:54 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

void	*routine()
{
	printf("Hello, World!\n");
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	t1, t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}

//this program prints "Hello, World!" twice in the standard 
//output in a parallel, the two threads execute the same thing 
//in the same time.

//but how can we make sure of that ?
