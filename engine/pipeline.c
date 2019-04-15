/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:37:26 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/15 14:55:53 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <crypto.h>

/*
** @note Execution wrapper for file descriptor
**       based processing.
*/

static ssize_t	exec(const int fd, t_hashing *hash,
							const t_options *opts,
							const t_input *input)
{
	ssize_t		ret;
	ssize_t		i;
	char		chunk[4096];

	i = 0;
	hash->i_f(hash);
	while ((ret = read(fd, chunk, hash->clen)) == hash->clen)
	{
		if (opts->p && input->method == STDIN)
			write(1, chunk, ret);
		hash->h_f(hash, chunk);
		i += ret;
	}
	i += ret;
	hash->p_f(hash, ret, chunk, i * 8);
	if (opts->p && input->method == STDIN)
		ft_printf("%s\n", chunk);
	hash->o_f(hash, input, opts);
	return (i);
}

/*
** @note Execution wrapper for
**       string input
*/

static ssize_t	exec_string(t_hashing *hash,
							const t_options *opts,
							const t_input *input)
{
	ssize_t		i;
	uint64_t	len;

	hash->i_f(hash);
	len = ft_strlen(input->input);
	i = len;
	(void)opts;
	while (i > hash->clen)
	{
		hash->h_f(hash, input->input + (len - i));
		i -= hash->clen;
	}
	hash->p_f(hash, i, input->input + (len - i), len * 8);
	hash->o_f(hash, input, opts);
	return (i);
}

/*
** @note Post execution helper to properly
**       close associated file descriptors.
*/

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
** @note Determine function set depending
**       configuration table.
*/

static void		prepare(t_hashing *hash,
						const t_options *opts,
						int i)
{
	while (g_interface[i].type != SENTINEL)
	{
		if (g_interface[i].type == opts->type)
		{
			if (*(g_interface[i].h_f) == NULL
				|| *(g_interface[i].i_f) == NULL
				|| *(g_interface[i].p_f) == NULL
				|| *(g_interface[i].o_f) == NULL)
			{
				ft_printf("Processing un-implemented algorithm.\n");
				exit(1);
			}
			else
			{
				hash->h_f = (*g_interface[i].h_f);
				hash->i_f = (*g_interface[i].i_f);
				hash->p_f = (*g_interface[i].p_f);
				hash->o_f = (*g_interface[i].o_f);
			}
		}
		i++;
	}
}

/*
** @note Meta pipeline that compute hashing
**       algorithm based on hashing functions
**       & helpers references.
*/

int				pipeline(const t_options *opts,
					const t_input *input)
{
	int			fd;
	t_hashing	hash;

	fd = STDIN_FILENO;
	ft_bzero(&hash, sizeof(t_hash));
	prepare(&hash, opts, 0x0);
	if (input->method == STDIN)
		exec(fd, &hash, opts, input);
	else if (input->method == FARG && input->input != NULL)
	{
		if ((fd = ffopen(input->input)) < 0)
			return (fd);
		exec(fd, &hash, opts, input);
		return (post_process(fd));
	}
	else if (input->method == STRING && input->input != NULL)
		exec_string(&hash, opts, input);
	return (0);
}
