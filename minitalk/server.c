/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachaki <ybachaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:41:56 by ybachaki          #+#    #+#             */
/*   Updated: 2022/04/04 02:57:04 by ybachaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handler(int sig)
{
	static char	x;
	static int	i;
	static int	count;

	if (count == 0)
	{
		count = 0;
		x = '\0';
		i = 1;
	}
	if (sig == SIGUSR1)
		x = x | i;
	i = i << 1;
	count++;
	if (count == 8)
	{
		write(1, &x, 1);
		count = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "Server PID : ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		pause();
	return (0);
}
