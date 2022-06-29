/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:36:15 by gromero-          #+#    #+#             */
/*   Updated: 2022/05/23 14:41:11 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstr(char *s, int *res)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", res);
		return ;
	}
	write (1, s, ft_strlen(s));
	*res += ft_strlen(s);
}
