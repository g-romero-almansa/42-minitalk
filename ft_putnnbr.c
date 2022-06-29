/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:50:31 by gromero-          #+#    #+#             */
/*   Updated: 2022/05/30 15:17:07 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnnbr(int num, int *res)
{
	if (num == -2147483648)
		ft_putstr("-2147483648", res);
	else
	{
		if (num < 0)
		{
			ft_putchar('-', res);
			num *= -1;
			ft_putnnbr(num, res);
		}
		else if (num < 10)
			ft_putchar(num % 10 + '0', res);
		else
		{
			ft_putnnbr((num / 10), res);
			ft_putchar((num % 10 + '0'), res);
		}
	}
}
