/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:19:35 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/12 14:23:40 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <crypto.h>

int			pad_512(t_hashing *hash,
				ssize_t ret,
				const char *chunk,
				uint64_t len)
{
	char	data[2048];

	ft_memcpy(data, chunk, ret);
	data[ret++] = 0x80;
	while (ret % hash->clen != hash->clen - 8)
		data[ret++] = 0x00;
	ft_memcpy(data + ret, &len, sizeof(len));
	md5_hash(hash, data);
	if (ret > hash->clen)
		md5_hash(hash, data);
	return (1);
}

int			pad_sha256(t_hashing *hash,
				ssize_t ret,
				const char *chunk,
				uint64_t len)
{
	char	data[128];

	ft_memcpy(data, chunk, ret);
	data[ret++] = 0x80;
	while (ret % hash->clen != hash->clen - 8)
		data[ret++] = 0x00;
	len = bswap64(len);
	ft_memcpy(data + ret, &len, sizeof(len));
	hash->h_f(hash, data);
	if (ret > hash->clen)
		hash->h_f(hash, data + hash->clen);
	return (1);
}

uint32_t	bswap32(uint32_t x)
{
	return (((x >> 24) & 0xff)
			| ((x << 8) & 0xff0000)
			| ((x >> 8) & 0xff00)
			| ((x << 24) & 0xff000000));
}

uint64_t	bswap64(uint64_t x)
{
	x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
	x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
	x = (x & 0x00FF00FF00FF00FF) << 8 | (x & 0xFF00FF00FF00FF00) >> 8;
	return (x);
}
