/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:07:40 by anthrodr          #+#    #+#             */
/*   Updated: 2023/04/21 13:27:13 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	pr_len;

	pr_len = 0;
	if (format == 'c')
		pr_len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		pr_len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		pr_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		pr_len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		pr_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		pr_len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		pr_len += ft_printpercent();
	return (pr_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		pr_lenght;

	i = 0;
	pr_lenght = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			pr_lenght += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			pr_lenght += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (pr_lenght);
}
