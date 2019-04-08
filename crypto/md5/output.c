/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:07:54 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/08 16:37:25 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <crypto.h>

int		md5_print(t_hashing *hash, const char *input)
{
	ft_printf("MD5 (%s) = %x%x%x%x\n",
			  input,
			  hash->state[0],
			  hash->state[1],
			  hash->state[2],
			  hash->state[3]);
	return (1);
}
