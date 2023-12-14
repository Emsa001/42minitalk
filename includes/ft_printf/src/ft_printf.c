/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:21:57 by escura            #+#    #+#             */
/*   Updated: 2023/12/12 16:55:24 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse(const char **format, t_settings *settings)
{
	if (**format == 'c')
		ft_putchar((int)settings->content, settings);
	else if (**format == 's')
	{
		if (settings->content == NULL)
			ft_putstr("(null)", settings);
		else
			ft_putstr((char *)settings->content, settings);
	}
	else if (**format == 'd' || **format == 'i')
		ft_putnbr((int)settings->content, settings);
	else if (**format == 'u')
		ft_putnbr((unsigned int)settings->content, settings);
	else if (**format == 'x')
		ft_puthex((unsigned int)settings->content, HEXA_LOWER, settings);
	else if (**format == 'X')
		ft_puthex((unsigned int)settings->content, HEXA_CAP, settings);
	else if (**format == 'p')
		ft_putptr(settings->content, settings);
	else if (**format == '%')
		ft_putchar('%', settings);
	(*format)++;
}

void	ft_convert(va_list args, const char *format, t_settings *settings)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			settings->content = va_arg(args, void *);
			ft_parse(&format, settings);
		}
		else
			ft_putchar(*format++, settings);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_settings	settings;

	(&settings)->content = NULL;
	(&settings)->printed = 0;
	va_start(args, format);
	ft_convert(args, format, &settings);
	va_end(args);
	return (settings.printed);
}
