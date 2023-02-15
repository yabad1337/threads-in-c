/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:00 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 14:33:36 by yabad            ###   ########.fr       */
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
	pthread_t	t1;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return (0);
}
