/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:59:06 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/16 11:43:49 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <libft.h>
# include <stdint.h>

# define TMD5    "md5"
# define TSHA224 "sha224"
# define TSHA256 "sha256"
# define TSHA384 "sha384"
# define TSHA512 "sha512"

/*
** @info Hashtype datastructure.
**       When element is pushed into
**       the engine, hashtype is used
**       to determine hash algorithm.
*/

typedef enum	e_hash {
	UNKNOWN = 0,
	MD5,
	SHA256,
	SHA224,
	SHA384,
	SHA512,
	SENTINEL
}				t_hash;

/*
** @info Processing method type
*/

typedef enum	e_meth
{
	FARG = 0,
	STDIN,
	STRING
}				t_meth;

/*
** @info Input type for method
**       processing
** @elem input is in the case of
**       file argument the filename
**       to process ~OR~ the raw
**       string input.
*/

typedef struct	s_input {
	t_meth		method;
	char		*input;
}				t_input;

/*
** @info Option parsing
**       structure.
*/

typedef struct	s_options {
	t_bool		p;
	t_bool		q;
	t_bool		r;
	t_hash		type;
}				t_options;

/*
** @info Hashing algorithm structure
**       storage.
** @elem state state storage
** @elem dlen message digest lenght
** @elem clen chunck lenght
** @elem i_f init fuction
** @elem h_f hash function
** @elem p_f padding function
** @elem o_f output function
*/

typedef struct	s_hashing
{
	uint32_t	state[8];
	ssize_t		dlen;
	ssize_t		clen;
	void		(*h_f)(struct s_hashing *, const char *);
	void		(*i_f)(struct s_hashing *);
	int			(*p_f)(struct s_hashing *, ssize_t, const char *, uint64_t);
	int			(*o_f)(struct s_hashing *, const struct s_input *,
					const struct s_options *opts);
	char		algo[16];
}				t_hashing;

/*
** @info Namespace prototypes.
*/

int				process(t_options *opts, t_dlist *plist);
t_bool			is_handlable(t_options *opts, char *tipep);
t_hash			hashtype(char *type);
void			memoize(t_meth method, char *entities, t_dlist **head);
void			parseopts(t_options *opts, int ac, char **av, t_dlist **p);
void			parseinput(int argc, char *argv[], t_dlist **plist);
int				fferror(const char *msg, const char *file);
int				ffopen(const char *path);
void			usage(void);
int				pipeline(const t_options *opts,
					const t_input *input);
uint_fast32_t	clean_runtime(t_options *opts,
					t_dlist **dlist);

#endif
