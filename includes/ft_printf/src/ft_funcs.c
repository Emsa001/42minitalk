/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:28:40 by escura            #+#    #+#             */
/*   Updated: 2023/12/12 14:50:58 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_digits(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_ptrlen(void *ptr)
{
	unsigned long long	d;
	int					len;

	d = (unsigned long long)ptr;
	len = 2;
	if (d == 0)
		len++;
	while (d > 0)
	{
		d /= 16;
		len++;
	}
	return (len);
}

int	ft_hexlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}
