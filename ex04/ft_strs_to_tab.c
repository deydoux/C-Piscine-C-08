/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:40:53 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/20 08:53:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock_strs;
	int			i;

	stock_strs = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_strs)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		stock_strs[i].str = av[i];
		stock_strs[i].size = ft_strlen(stock_strs[i].str) + 1;
		stock_strs[i].copy = malloc(sizeof(char) * stock_strs[i].size);
		if (!stock_strs[i].copy)
		{
			while (--i)
				free(stock_strs[i].copy);
			free(stock_strs);
			return (NULL);
		}
		ft_strcpy(stock_strs[i].copy, stock_strs[i].str);
	}
	stock_strs[i].str = 0;
	stock_strs[i].size = 1;
	stock_strs[i].copy = 0;
	return (stock_strs);
}
