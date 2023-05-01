/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:24:24 by anthrodr          #+#    #+#             */
/*   Updated: 2023/04/14 11:24:29 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	offset;
	char	*p;

	p = s;
	offset = 0;
	while (offset < n)
	{
		p[offset] = 0;
		offset++;
	}
}
