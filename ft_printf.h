/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:30:14 by gromero-          #+#    #+#             */
/*   Updated: 2022/05/23 15:03:20 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c, int *res);

void	ft_puthexa(unsigned long long num, int *res);

void	ft_putnbr(unsigned int num, int *res);

void	ft_putnbr_hexa(unsigned long long num, char *base, int *res);

void	ft_putnnbr(int num, int *res);

void	ft_putstr(char *s, int *res);

int		ft_strlen(char const *s);

void	ft_format(va_list imp, char const *txt, int i, int *res);

int		ft_printf(char const *txt, ...);

#endif
