/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:07:32 by aidgomez          #+#    #+#             */
/*   Updated: 2023/08/01 16:07:32 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "printf/ft_printf.h"

void	signal_handler(int signal_id, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	c = 0;
	int						client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (SIGUSR1 == signal_id)
		c = (c << 1) | 0b00000001;
	else if (SIGUSR2 == signal_id)
		c = c << 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sign;

	write(1, "\n", 1);
	printf("PID: %d\n", getpid());
	write(1, "\n", 1);
	sign.sa_sigaction = signal_handler;
	sign.sa_flags = SA_NODEFER;
	sigemptyset(&sign.sa_mask);
	sigaction(SIGUSR1, &sign, NULL);
	sigaction(SIGUSR2, &sign, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
