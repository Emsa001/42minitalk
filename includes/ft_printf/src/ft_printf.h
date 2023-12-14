/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:41 by escura            #+#    #+#             */
/*   Updated: 2023/12/12 15:33:23 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"

typedef struct s_settings
{
	void	*content;
	int		printed;
}			t_settings;

void		ft_putchar(char c, t_settings *settings);
void		ft_putstr(char *str, t_settings *settings);
void		ft_putnbr(long int nb, t_settings *settings);
void		ft_puthex(unsigned int nb, char *hex, t_settings *settings);
void		ft_putptr(void *ptr, t_settings *settings);
int			ft_printf(const char *format, ...);
int			get_digits(long int n);

#endif
