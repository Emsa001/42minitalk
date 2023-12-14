/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:40:11 by escura            #+#    #+#             */
/*   Updated: 2023/12/14 14:48:23 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler_message(char **str, siginfo_t *client, int sequence[], int *i)
{
	static int	length = 1;
	char		*temp;

	temp = *str;
	*str = (char *)malloc(sizeof(char) * (length + 1));
	if (!*str)
		exit(EXIT_FAILURE);
	if (temp)
	{
		ft_strlcpy(*str, temp, length);
		free(temp);
	}
	(*str)[length - 1] = decoder(sequence);
	(*str)[length] = '\0';
	if ((*str)[length - 1] == '\0')
	{
		ft_printf("\e[1;35m Received » \e[0;37m%s\n", *str);
		free(*str);
		*str = NULL;
		length = 1;
		kill(client->si_pid, SIGUSR2);
	}
	else
		length += 1;
	(*i) = 0;
}

void	handler(int signal, siginfo_t *client, void *ucontext)
{
	static char	*str = NULL;
	static int	sequence[8];
	static int	i = 0;

	sequence[i++] = signal == SIGUSR1;
	if (i == 8)
		handler_message(&str, client, sequence, &i);
	ucontext = NULL;
}

static int	ft_pow(int base, int exp)
{
	int	result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

char	decoder(int *sequence)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 7;
	result = 0;
	while (i < 8)
		result += (sequence[i++] * ft_pow(2, n--));
	return ((char)result);
}
