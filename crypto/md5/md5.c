/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:21:32 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/08 12:12:50 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <engine.h>
#include <crypto.h>
#include <algorithms.h>

static int	process_md5(const int fd)
{
	int		r;
	char	chunk[MD5_CHUNK_SIZE];

	ft_memset(chunk, '\0', MD5_CHUNK_SIZE);
	while ((r = read(fd, chunk, MD5_CHUNK_SIZE)) > 0)
	{
		chunk[ft_strlen(chunk)] = '\1';
		ft_printf("Chunk read (ssize = %d): %s\n", ft_strlen(chunk), chunk);
		ft_bzero(chunk, MD5_CHUNK_SIZE);
	}
	return (r);
}

static int	post_process(const int fd)
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

int			md5(const t_options *opts,
				const t_input *input)
{
	int		fd;

	fd = 0;
	(void)opts;
	ft_printf("Processing MD5(\" %s \") with method %d\n",
		input->input,
		input->method);
	if (input->method == FARG && input->input != NULL)
		if ((fd = ffopen(input->input)) < 0)
			return (fd);
	process_md5(fd);
	post_process(fd);
	return (0);
}
