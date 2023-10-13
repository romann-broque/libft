/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:25:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/13 07:28:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_number(const char *str)
{
	while (ft_isdigit(*str))
		++str;
	return (*str == '\0');
}
