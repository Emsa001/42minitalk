/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:59 by escura            #+#    #+#             */
/*   Updated: 2023/12/12 14:45:09 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_settings *settings)
{
	write(1, &c, 1);
	settings->printed++;
}

void	ft_putstr(char *str, t_settings *settings)
{
	while (*str)
		ft_putchar(*(str++), settings);
}

void	ft_putnbr(long int nb, t_settings *settings)
{
	if (nb < 0)
	{
		ft_putchar('-', settings);
		nb = (unsigned int)(-nb);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, settings);
		ft_putnbr(nb % 10, settings);
	}
	else
		ft_putchar(nb + '0', settings);
}

void	ft_puthex(unsigned int nb, char *hex, t_settings *settings)
{
	if (nb == 0)
	{
		if ((int)settings->content == 0)
			ft_putchar('0', settings);
		return ;
	}
	ft_puthex(nb / 16, hex, settings);
	ft_putchar(hex[nb % 16], settings);
}

void	ft_putptr(void *ptr, t_settings *settings)
{
	unsigned long long	d;

	d = (unsigned long long)ptr;
	if (d == 0)
	{
		ft_putstr("0x", settings);
		if ((long int)settings->content == 0)
			ft_putstr("0", settings);
		return ;
	}
	ft_putptr((void *)(d / 16), settings);
	ft_putchar(HEXA_LOWER[d % 16], settings);
}
