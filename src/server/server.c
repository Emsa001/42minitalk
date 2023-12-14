/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:49:11 by escura            #+#    #+#             */
/*   Updated: 2023/12/13 15:20:50 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	header(pid_t pid)
{
	int			i;
	const char	*str[11] = {
		"\n\n\n\n",
		"\x1B[35m╭──────────────────────────────\
─────────────────────────────────╮\n",
		"   ███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n",
		"   ████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n",
		"   ██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n",
		"   ██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n",
		"   ██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n",
		"   ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n",
		"\x1B[35m╰──────────────────────────────\
─────────────────────────────────╯\n",
		"\n\n",
	};

	i = 0;
	while (str[i])
	{
		ft_printf("                      ");
		ft_printf("\e[1;34m%s", str[i++]);
	}
	ft_printf("                                    \x1B[35m%d", pid);
	ft_printf("                      \x1B[35mEmanuel Scura\n");
	ft_printf("                           \e[1;34m╰──────[  PID  ]──────╯");
	ft_printf("      ╰──────[  Author  ]──────╯\n\n\n");
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;
	sigemptyset(&(sig.sa_mask));
	pid = getpid();
	header(pid);
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	while (1)
		sleep(1);
	return (0);
}
