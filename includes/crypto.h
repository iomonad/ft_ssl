/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:13:11 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/12 12:03:02 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRYPTO_H
# define CRYPTO_H

# include <libft.h>
# include <engine.h>

# define MD5_CHUNK_SIZE 64

/*
** MD5 Prototypes
*/

void				md5_init(t_hashing *hash);
void				md5_hash(t_hashing *hash, const char *chunk);

/*
** SHA256 Prototypes
*/

void				sha256_init(t_hashing *hash);
void				sha256_hash(t_hashing *hash, const char *chunk);

/*
** Helper prototypes
*/

int					pad_512(t_hashing *hash, ssize_t ret,
						const char *chunk, uint64_t len);
int					pprinter(t_hashing *hash, const t_input *input);

/*
** Interface table
*/

typedef struct		s_interface
{
	t_hash			type;
	void			(*h_f)(struct s_hashing *, const char *);
	void			(*i_f)(struct s_hashing *);
	int				(*p_f)(struct s_hashing *, ssize_t, const char *, uint64_t);
	int				(*o_f)(struct s_hashing *, const struct s_input *);
}					t_interface;

/*
** Utils function hashset reference
*/

static t_interface	g_interface[] = {
	{MD5, md5_hash, md5_init, pad_512, pprinter},
	{SHA224, NULL, NULL, NULL, NULL},
	{SHA256, sha256_hash, sha256_init, pad_512, pprinter},
	{SHA384, NULL, NULL, NULL, NULL},
	{SHA512, NULL, NULL, NULL, NULL},
	{SENTINEL, NULL, NULL, NULL, NULL}
};

#endif
