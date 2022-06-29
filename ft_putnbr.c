/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:43:21 by gromero-          #+#    #+#             */
/*   Updated: 2022/05/23 15:05:47 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr(unsigned int num, int *res)
{
	if (num < 10)
		ft_putchar((num % 10 + '0'), res);
	else
	{		
		ft_putnbr(num / 10, res);
		ft_putchar((num % 10 + '0'), res);
	}
}
