/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8-thread_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:31:58 by yabad             #+#    #+#             */
/*   Updated: 2023/02/15 16:44:18 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define DICE 10

// this program will roll 10 dices in the same time using threads
// then return the values

void	*roll_dice(void *p)
{
	int	*value;

	(void)p;
	value = (int *)malloc(sizeof(int));
	if (!value)
		return (NULL);
	*value = rand() % 6 + 1;
	return (value);
}

int	main(int ac, char **av)
{
	pthread_t	th[DICE];
	int			*ret_th;
	int			i;

	i = 0;
	srand(time(NULL));
	while (i < DICE)
	{
		if (pthread_create(th + i, NULL, &roll_dice, NULL))
		{
			printf("Failed creating a thread\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < DICE)
	{
		if (pthread_join(th[i], (void **)&ret_th))
			return (2);
		printf("DICE %d : %d\n", i, *ret_th);
		free(ret_th);
		i++;
	}
	return (0);
}
