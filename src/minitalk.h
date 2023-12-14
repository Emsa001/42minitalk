/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:58:00 by escura            #+#    #+#             */
/*   Updated: 2023/12/12 20:40:44 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../includes/ft_printf/src/ft_printf.h"
# include "../includes/libft/libft.h"
# include <signal.h>
# include <stdlib.h>

void	sender(pid_t pid, unsigned char c);
void	handle_string(pid_t pid, char *str);
void	client_handler(int signal, siginfo_t *client, void *ucontext);

char	decoder(int *sequence);
void	handler(int signal, siginfo_t *client, void *ucontext);

#endif
