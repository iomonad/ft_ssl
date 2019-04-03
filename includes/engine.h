/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:59:06 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/03 16:15:05 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <libft.h>

# define TMD5    "md5"
# define TSHA256 "sha256"

/*
** @info Hashtype datastructure.
**       When element is pushed into
**       the engine, hashtype is used
**       to determine hash algorithm.
*/

typedef enum	e_hash {
	UNKNOWN = 0,
	MD5 = 1,
	SHA256 = 2
}				t_hash;

/*
** @info Option parsing
**       structure.
*/

typedef struct	s_options {
	t_bool		p;
	t_bool		q;
	t_bool		r;
	t_hash		type;
	char		*string;
}				t_options;

/*
** @info Namespace prototypes.
*/

int				process(t_options *opts, t_list *plist);
t_bool			is_handlable(t_options *opts, t_list *plist, char *tipep);
void			usage(void);

#endif
