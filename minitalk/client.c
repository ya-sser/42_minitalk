/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachaki <ybachaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:41:40 by ybachaki          #+#    #+#             */
/*   Updated: 2022/04/04 02:44:54 by ybachaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	bit_sender(char *argv, int pid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(argv + j))
	{
		while (i < 8)
		{
			if (*(argv + j) & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(0);
			}
			else if (kill(pid, SIGUSR2) == -1)
				exit(0);
			*(argv + j) = *(argv + j) >> 1;
			i++;
			usleep(500);
		}
		j++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Wrong number of arguments\n", 26);
		exit (1);
	}
	while (*(*(argv + 1) + i))
	{
		if (!ft_isdigit(*(*(argv + 1) + i)))
		{
			write(1, "Wrong PID\n", 10);
			exit (1);
		}
		i++;
	}
	pid = ft_atoi(*(argv + 1));
	bit_sender (*(argv + 2), pid);
	return (0);
}
