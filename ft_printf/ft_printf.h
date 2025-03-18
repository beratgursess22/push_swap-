/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:58:43 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:58:45 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_unsing(unsigned int u);
int		ft_pointer(unsigned long p);
int		ft_hex(unsigned int x, int b);

int		ft_check(char c, va_list arg);
int		ft_check2(char c, va_list arg);
int		ft_printf(const char *str, ...);

#endif
