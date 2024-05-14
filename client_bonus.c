/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:44:51 by aidgomez          #+#    #+#             */
/*   Updated: 2023/08/16 16:50:37 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "printf/ft_printf.h"

int	g_flag = 1;

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}	
	return (nbr * sign);
}

void	signal_handler(int signal_id, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (SIGUSR1 == signal_id)
	{
		g_flag = 0;
		printf("Senal recibida por servidor\n");
	}
}

void	signal_kill(pid_t pid, char c)
{
	int	bit_moves;

	bit_moves = 0;
	while (bit_moves < 8)
	{
		g_flag = 1;
		if ((c << bit_moves) & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_moves++;
		while (g_flag)
			usleep(1);
	}
}

void	str_shipment(pid_t pid, char *str)
{
	while (*str)
	{
		signal_kill(pid, *str);
		str++;
	}
	signal_kill(pid, '\n');
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sign;

	sign.sa_sigaction = signal_handler;
	sign.sa_flags = SA_SIGINFO;
	sigemptyset(&sign.sa_mask);
	sigaction(SIGUSR1, &sign, NULL);
	if (argc != 3)
		printf("ERROR!!! Envía sólo 3 argumentos: 1.Programa 2.PID 3.String\n");
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
			str_shipment(pid, argv[2]);
		else
			printf("ERROR!!! El PID debe ser un número\n");
	}
	return (0);
}
