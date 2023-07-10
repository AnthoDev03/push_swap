/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:34:15 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 14:34:20 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_integer(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (false);
		}
		str++;
	}
	return (true);
}

bool	has_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	max_length;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strlen(argv[i]) > ft_strlen(argv[j]))
				max_length = ft_strlen(argv[i]);
			else
				max_length = ft_strlen(argv[j]);
			if (ft_strncmp(argv[i], argv[j], max_length) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

long long	str_to_ll(const char *str)
{
	long long	number;
	int			sign;

	number = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str)
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}

bool	isoperateur(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' || argv[i][0] == '+')
		{
			if (!(argv[i][1] >= '0' && argv[i][1] <= '9'))
			{
				return (false);
			}
		}
		i++;
	}
	return (true);
}

int	test(int argc, char **argv)
{
	int			i;
	long long	number;

	if (isoperateur(argv) == false)
		return (0);
	if (has_duplicates(argc, argv))
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
			return (0);
		number = str_to_ll(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
