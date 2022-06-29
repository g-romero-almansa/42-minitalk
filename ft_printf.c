/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:37:11 by gromero-          #+#    #+#             */
/*   Updated: 2022/05/23 15:00:44 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_format(va_list args, char const *txt, int i, int *res)
{	
	if (txt[i + 1] == 'c')
		ft_putchar(va_arg(args, int), res);
	else if (txt[i + 1] == 's')
		ft_putstr(va_arg(args, char *), res);
	else if (txt[i + 1] == 'p')
	{	
		ft_putstr("0x", res);
		ft_puthexa(va_arg(args, unsigned long long), res);
	}
	else if (txt[i + 1] == 'd')
		ft_putnnbr(va_arg(args, int), res);
	else if (txt[i + 1] == 'i')
		ft_putnnbr(va_arg(args, int), res);
	else if (txt[i + 1] == 'u')
		ft_putnbr(va_arg(args, unsigned int), res);
	else if (txt[i + 1] == 'x')
		ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef", res);
	else if (txt[i + 1] == 'X')
		ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF", res);
	else if (txt[i + 1] == '%')
		ft_putchar('%', res);
}

int	ft_printf(char const *txt, ...)
{
	int		i;
	int		res;
	va_list	args;

	i = 0;
	res = 0;
	va_start (args, txt);
	while (txt[i])
	{
		if (txt[i] == '%')
		{
			ft_format(args, txt, i, &res);
			i++;
		}
		else
			ft_putchar(txt[i], &res);
		i++;
	}
	va_end(args);
	return (res);
}
