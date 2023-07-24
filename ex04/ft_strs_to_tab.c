/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:40:53 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/24 10:03:45 by deydoux          ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock_strs;
	int			i;

	stock_strs = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_strs)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock_strs[i].str = ft_strdup(av[i]);
		stock_strs[i].size = ft_strlen(av[i]);
		stock_strs[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock_strs[i].str = 0;
	return (stock_strs);
}
