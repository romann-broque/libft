/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:49:46 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/04 09:57:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
