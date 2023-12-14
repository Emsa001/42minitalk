/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:27:33 by escura            #+#    #+#             */
/*   Updated: 2023/12/14 14:48:17 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	client_handler(int signal, siginfo_t *client, void *ucontext)
{
	if (signal == SIGUSR2)
	{
		ft_printf("\n\e[1;32m SUCCESS » \e[0;37m");
		ft_printf("Message succesfully received by server!\n\n");
		exit(EXIT_SUCCESS);
	}
	client = NULL;
	ucontext = NULL;
}

void	error_case(pid_t pid)
{
	ft_printf("\n\e[1;31m FAILED » \e[0;37mSomething went wrong when\
 sending signal to \e[1;35m%d\n\n", pid);
	exit(EXIT_FAILURE);
}

void	sender(pid_t pid, unsigned char c)
{
	int	i;
	int	n;

	i = 0;
	n = 7;
	while (i < 8)
	{
		if (c & (1 << n))
		{
			if (kill(pid, SIGUSR1) == -1)
				error_case(pid);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_case(pid);
		}
		i++;
		n--;
		usleep(100);
	}
}

void	handle_string(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		sender(pid, str[i++]);
	sender(pid, '\0');
}
