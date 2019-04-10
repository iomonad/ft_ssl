/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:13:11 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/10 13:32:28 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRYPTO_H
# define CRYPTO_H

# include <libft.h>
# include <engine.h>

# define MD5_CHUNK_SIZE 64

void				init_md5(t_hashing *hash);
void				md5_hash(t_hashing *hash, const char *chunk);
int					pprinter(t_hashing *hash, const t_input *input);

/*
** Helper prototypes
*/

int					pad_512(t_hashing *hash, ssize_t ret,
						const char *chunk, uint64_t len);

typedef struct		s_interface
{
	t_hash			type;
	void			(*h_f)(struct s_hashing *, const char *);
	void			(*i_f)(struct s_hashing *);
	int				(*p_f)(struct s_hashing *, ssize_t, const char *, uint64_t);
	int				(*o_f)(struct s_hashing *, const struct s_input *);
}					t_interface;

static t_interface	g_interface[] = {
	{MD5, md5_hash, init_md5, pad_512, pprinter},
	{SHA224, NULL, NULL, NULL, NULL},
	{SHA256, NULL, NULL, NULL, NULL},
	{SHA384, NULL, NULL, NULL, NULL},
	{SHA512, NULL, NULL, NULL, NULL},
	{SENTINEL, NULL, NULL, NULL, NULL}
};

#endif
