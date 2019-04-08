/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:28:53 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/08 16:54:58 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include <crypto.h>
# include <engine.h>

# define MD5_CHUNK_SIZE 64

void		init_md5(t_hashing *hash);
void		md5_hash(t_hashing *hash, const char *chunk);
int			md5_print(t_hashing *hash, const char *input);
int			md5(const t_options *opts,
				const t_input *input);

#endif
