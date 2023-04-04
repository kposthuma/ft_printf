/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printwrite.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:15:35 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/04 13:57:55 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr_printf(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (putstr_printf("(null)"), 6);
	while (s[i])
		i += putchar_printf(s[i]);
	return (i);
}

int	putnbr_printf(unsigned int n)
{
	int				len;
	unsigned int	t;

	len = 0;
	t = n;
	if (n == 0)
		len = 1;
	while (t)
	{
		t = t / 10;
		len++;
	}	
	if (n < 10)
		putchar_printf(n + 48);
	else
	{
		putnbr_printf(n / 10);
		putnbr_printf(n % 10);
	}
	return (len);
}

int	ft_printnbr(int n)
{
	if (n == -2147483648)
		return (putstr_printf("-2147483648"));
	if (n < 0)
	{
		n = -n;
		putchar_printf('-');
		return (putnbr_printf((unsigned int)n) + 1);
	}
	else
		return (putnbr_printf((unsigned int)n));
}
