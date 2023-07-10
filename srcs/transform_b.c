/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:35:28 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 14:35:29 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*transform(int argc, char **argv)
{
	int	*data;
	int	*data2;

	data = (int *)malloc(sizeof(int) * (argc - 1));
	if (!data)
		return (NULL);
	data2 = (int *)malloc(sizeof(int) * (argc - 1));
	if (!data2)
	{
		free(data);
		return (NULL);
	}
	fill_data_array(argc, argv, data);
	calculate_new_data_array(data, data2, argc - 1);
	free(data);
	return (data2);
}
