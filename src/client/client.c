/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:17:11 by escura            #+#    #+#             */
/*   Updated: 2023/12/13 14:59:50 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sig;

	if (argc != 3)
	{
		ft_printf("\n\e[1;33m FAILED » \e[0;37mCorrect usage: ");
		ft_printf("%s <pid> <message>\n\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sig.sa_sigaction = client_handler;
	sigemptyset(&(sig.sa_mask));
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("\n\e[1;31m FAILED » \e[0;37m%s", "Wrong PID!\n\n");
		exit(EXIT_FAILURE);
	}
	handle_string(pid, argv[2]);
}
