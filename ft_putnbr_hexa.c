/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:58:56 by gromero-          #+#    #+#             */
/*   Updated: 2022/05/20 14:39:13 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned long long num, char *base, int *res)
{
	if (num >= 16)
		ft_putnbr_hexa((num / 16), base, res);
	ft_putchar(base[num % 16], res);
}
