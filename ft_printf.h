/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 11:58:45 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/04 13:58:24 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_decider(const char chr, va_list args);
int	putchar_printf(char c);
int	putstr_printf(char *s);
int	ft_printnbr(int n);
int	putnbr_printf(unsigned int n);
int	ft_puthex(unsigned int n, const char A);
int	ft_hexupp(unsigned int n);
int	ft_hexlow(unsigned int n);
int	ft_putptr(size_t n);

#endif