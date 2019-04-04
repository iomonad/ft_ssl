/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:13:11 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/04 16:29:30 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRYPTO_H
# define CRYPTO_H

# include <libft.h>
# include <engine.h>

# include <algorithms.h>

typedef struct s_interface
{
	t_hash type;
	int (*hashf)(const char *chunk);
} t_interface;

static t_interface g_interface[] = {
	{MD5, md5},
	{SHA224, NULL},
	{SHA256, NULL},
	{SHA384, NULL},
	{SHA512, NULL},
	{SENTINEL, NULL}
};

#endif
