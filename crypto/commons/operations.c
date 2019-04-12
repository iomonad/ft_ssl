/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:03:19 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/12 14:22:40 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <crypto.h>

/*
** See: https://crypto.stackexchange.com/questions/5358/what
**                -does-maj-and-ch-mean-in-sha-256-algorithm
*/

uint32_t	right_rotate(uint32_t n, uint32_t d)
{
	return ((n >> d) | (n << (32 - d)));
}

/*
** `Ch` stands for choose or choice, as the 𝑥 input
** chooses if the output is from 𝑦 or from 𝑧.
** More precisely, for each bit index, that result bit is according
** to the bit from 𝑦 (or respectively 𝑧 ) at this index,
** depending on if the bit from 𝑥 at this index is 1 (or respectively 0).
*/

uint32_t	choose256(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (~x & z));
}

/*
** `Maj` stands for majority: for each bit index,
** that result bit is according to the majority of
** the 3 inputs bits for 𝑥 𝑦 and 𝑧 at this index.
*/

uint32_t	majority256(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

/*
** Epsilon implementation first variation
*/

uint32_t	epsilon2561(uint32_t x)
{
	return (right_rotate(x, 2)
			^ right_rotate(x, 13)
			^ right_rotate(x, 22));
}

/*
** Epsilon implementation second variation
*/

uint32_t	epsilon2562(uint32_t x)
{
	return (right_rotate(x, 6)
			^ right_rotate(x, 11)
			^ right_rotate(x, 25));
}
