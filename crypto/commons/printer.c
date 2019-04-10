/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:29:52 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/10 13:33:14 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>

/*
** @note MD5 Pretty Printer
*/

int				pprinter(t_hashing *hash,
					const t_input *input)
{
	char		*str;
	uint32_t	i;

	i = 0;
	str = (char*)hash->state;
	if (input->method == FARG)
		ft_printf("MD5 (%s) = ", input->input);
	else if (input->method == STRING)
		ft_printf("MD5 (\"%s\") = ", input->input);
	while (i < hash->dlen)
		ft_printf("%2.2hhx", str[i++]);
	write(1, "\n", 1);
	return (1);
}
