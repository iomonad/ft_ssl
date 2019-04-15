/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:29:52 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/15 14:58:46 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>
#include <crypto.h>

/*
** @note MD5 Pretty Printer
*/

int				pprinter(t_hashing *hash,
					const t_input *input,
					const t_options *opts)
{
	char		*str;
	uint32_t	i;

	i = 0;
	str = (char*)hash->state;
	if (input->method == FARG && !opts->r)
		ft_printf("%s (%s) = ", hash->algo, input->input);
	else if (input->method == STRING && !opts->r)
		ft_printf("%s (\"%s\") = ", hash->algo, input->input);
	while (i < hash->dlen)
		ft_printf("%2.2hhx", str[i++]);
	if (opts->r && input->method != STDIN)
		ft_printf(" %s\n", input->input);
	else
		write(1, "\n", 1);
	return (1);
}

int				pprinter256(t_hashing *hash,
					const t_input *input,
					const t_options *opts)
{
	ssize_t		i;
	char		*str;

	i = 0;
	str = (char*)hash->state;
	if (input->method == FARG && !opts->r)
		ft_printf("%s (%s) = ", hash->algo, input->input);
	else if (input->method == STRING && !opts->r)
		ft_printf("%s (\"%s\") = ", hash->algo, input->input);
	while (i < 8)
	{
		hash->state[i] = bswap32(hash->state[i]);
		i++;
	}
	i = 0;
	while (i < hash->dlen)
		ft_printf("%2.2hhx", str[i++]);
	if (opts->r && input->method != STDIN)
		ft_printf(" %s\n", input->input);
	else
		write(1, "\n", 1);
	return (1);
}
