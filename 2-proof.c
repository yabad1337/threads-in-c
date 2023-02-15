/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-proof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:00 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 14:53:42 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// we will answer the previous question in this section

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

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}

// this program will print "Thread Begins" twice for the two threads created
// then it will sleep and print "Thread Ends" twice again
// this proves that the function routine is executed in parallel by two threads