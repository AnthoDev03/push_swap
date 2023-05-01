/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:29:21 by anthrodr          #+#    #+#             */
/*   Updated: 2023/04/21 13:31:16 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printstr(char *format)
{
	int		i;

	i = 0;
	if (format == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (format[i])
	{
		ft_putchar_fd(format[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
