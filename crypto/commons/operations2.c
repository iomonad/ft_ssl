/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:26:20 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/12 13:27:55 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <crypto.h>

uint32_t	sigma256(uint32_t x)
{
	return (right_rotate(x, 7) ^ right_rotate(x, 18) ^ (x >> 3));
}

uint32_t	sigma2561(uint32_t x)
{
	return (right_rotate(x, 17) ^ right_rotate(x, 19) ^ (x >> 10));
}
