/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:50:04 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/15 13:54:12 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>
#include <crypto.h>

void	sha224_init(t_hashing *hash)
{
	hash->state[0] = 0xc1059ed8;
	hash->state[1] = 0x367cd507;
	hash->state[2] = 0x3070dd17;
	hash->state[3] = 0xf70e5939;
	hash->state[4] = 0xffc00b31;
	hash->state[5] = 0x68581511;
	hash->state[6] = 0x64f98fa7;
	hash->state[7] = 0xbefa4fa4;
	hash->dlen = 28;
	hash->clen = 64;
}
