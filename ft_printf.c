/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 11:52:18 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/04 13:54:46 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_puthex(unsigned int n, const char A)
{
	int				len;
	unsigned int	t;

	len = 0;
	t = n;
	if (n == 0)
		len = 1;
	while (t)
	{
		t = t / 16;
		len++;
	}	
	if (n < 16)
	{
		if (A == 'x')
			ft_hexlow(n);
		else
			ft_hexupp(n);
	}
	else
	{
		ft_puthex((n / 16), A);
		ft_puthex((n % 16), A);
	}
	return (len);
}

int	ft_hexupp(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
		ft_putchar(n - 10 + 'A');
	return (0);
}

int	ft_hexlow(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
		ft_putchar(n - 10 + 'a');
	return (0);
}

int	ft_decider(const char chr, va_list args)
{
	int	i;

	i = 0;
	if (chr == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (chr == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (chr == 'p')
		i = ft_putptr(va_arg(args, size_t));
	else if (chr == 'd' || chr == 'i')
		i = ft_printnbr(va_arg(args, int));
	else if (chr == 'u')
		i = ft_putnbr_(va_arg(args, unsigned int));
	else if (chr == 'x' || chr == 'X')
		i = ft_puthex(va_arg(args, unsigned int), chr);
	else if (chr == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	size_t	ind;
	int		val;

	va_start(args, string);
	ind = 0;
	val = 0;
	while (string[ind])
	{
		if (string[ind] == '%')
		{
			ind++;
			if (!string[ind])
				break ;
			val += ft_decider(string[ind], args);
		}
		else
			val += ft_putchar(string[ind]);
		ind++;
	}
	va_end(args);
	return (val);
}
