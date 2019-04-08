/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:21:32 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/08 16:36:03 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <engine.h>
#include <crypto.h>
#include <algorithms.h>
#include <stdlib.h>

static ssize_t	process_md5(const int fd, t_hashing *hash,
						const t_options *opts)
{
	ssize_t ret, i = 0;
	char	chunk[MD5_CHUNK_SIZE];

	init_md5(hash);
	ft_memset(chunk, '\0', MD5_CHUNK_SIZE);
	while ((ret = read(fd, chunk, MD5_CHUNK_SIZE)) == hash->clen)
	{
		if (opts->p)
			write(1, chunk, ret);
		md5_hash(hash, chunk);
		i += ret;
	}
	pad_512(hash, ret, chunk, i * 8);
	return (i);
}

static int		post_process(const int fd)
{
	if (fd != 0)
	{
		if (close(fd) < 0)
		{
			ft_printf("Error while closing file descriptor %d.\n", fd);
			return (-1);
		}
	}
	return (0);
}

/*
** @note
*/

int				md5(const t_options *opts,
				const t_input *input)
{
	int			fd = 0;
	t_hashing	hash;

	ft_bzero(&hash, sizeof(t_hash));
	if (input->method == FARG && input->input != NULL)
		if ((fd = ffopen(input->input)) < 0)
			return (fd);
	process_md5(fd, &hash, opts);
	post_process(fd);
	md5_print(&hash, input->input);
	return (0);
}
