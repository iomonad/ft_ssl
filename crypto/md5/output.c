/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:07:54 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/09 13:43:11 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <crypto.h>

/*
** @note MD5 Pretty Printer
*/

int				md5_print(t_hashing *hash,
						const char *input)
{
	char		*str;
	uint32_t	i;

	i = 0;
	str = (char*)hash->state;
	ft_printf("MD5 (%s) = ", input);
	while (i < hash->dlen)
		ft_printf("%2.2hhx", str[i++]);
	write(1, "\n", 1);
	return (1);
}
