/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:21:32 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/09 10:49:37 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <engine.h>
#include <crypto.h>
#include <algorithms.h>
#include <stdlib.h>

/*
** @note Process md5 algorithm by
**       polling lazyly file descriptor
*/

static ssize_t	process_md5(const int fd, t_hashing *hash,
							const t_options *opts,
							const t_input *input)
{
	ssize_t		ret;
	ssize_t		i;
	char		chunk[4096];

	i = 0;
	init_md5(hash);
	while ((ret = read(fd, chunk, hash->clen)) == hash->clen)
	{
		if (opts->p)
			write(1, chunk, ret);
		md5_hash(hash, chunk);
		i += ret;
	}
	i += ret;
	pad_512(hash, ret, chunk, i * 8);
	printf("Final State: \n");
	printf("state[0] = 0x%x\n", hash->state[0]);
	printf("state[1] = 0x%x\n", hash->state[1]);
	printf("state[2] = 0x%x\n", hash->state[2]);
	printf("state[3] = 0x%x\n", hash->state[3]);
	md5_print(hash, input->input);
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
	process_md5(fd, &hash, opts, input);
	post_process(fd);
	return (0);
}
