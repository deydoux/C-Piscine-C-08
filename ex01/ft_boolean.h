/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:50:35 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/20 08:38:53 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# include <unistd.h>
# define FT_BOOLEAN_H

# define EVEN(n) (n % 2 == 0)

typedef enum boolean
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

# define EVEN_MSG "I have an even number of arguments."
# define ODD_MSG "I have an odd number of arguments."
# define SUCCESS 0

#endif
