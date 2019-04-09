/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:19:35 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/09 13:32:13 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <crypto.h>

int		pad_512(t_hashing *hash,
				ssize_t ret,
				const char *chunk,
				uint64_t len)
{
	char	data[2048];

	printf("----- PADDING -----\n");

	memcpy(data, chunk, ret);
	data[ret++] = 0x80;

	printf("pad512: ret=%zu len=%llu\n", ret, len);

	while (ret % hash->clen != hash->clen - 8)
		data[ret++] = 0x00;
	memcpy(data + ret, &len, sizeof(len));
	md5_hash(hash, data);
	if (ret > hash->clen)
		md5_hash(hash, data);
	return (1);
}
