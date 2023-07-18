/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:40:53 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/18 15:27:28 by deydoux          ###   ########.fr       */
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

struct s_stock_str	*ft_strs_to_str(int ac, char **av)
{
	int			i;
	t_stock_str	*stock_strs;
	t_stock_str	stock_str;

	i = -1;
	stock_strs = malloc(sizeof(t_stock_str) * (ac + 1));
	while (stock_strs && ++i < ac)
	{
		stock_str.str = av[i];
		stock_str.size = ft_strlen(stock_str.str) + 1;
		stock_str.copy = malloc(sizeof(char) * stock_str.size);
		if (!stock_str.copy)
		{
			while (--i)
				free(stock_strs[i].copy);
			free(stock_strs);
			return (NULL);
		}
		ft_strcpy(stock_str.copy, stock_str.str);
		stock_strs[i] = stock_str;
	}
	stock_strs[i].str = "\0";
	stock_strs[i].size = 1;
	stock_strs[i].copy = "\0";
	return (stock_strs);
}
