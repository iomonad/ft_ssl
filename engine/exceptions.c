/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:53:41 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/15 13:56:59 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <engine.h>

/*
** @info: Do I need to explain ?
*/

static void	invalid_algo(char *tipep)
{
	ft_fprintf(2, "ft_ssl: Error: '%s' is an invalid command.\n", tipep);
	ft_fprintf(2, "Standard commands:\n\n");
	ft_fprintf(2, "Message Digest commands:\nmd5\nsha224\nsha256\n");
	exit(1);
}

/*
** @info: Error handling sequence
** @todo: Handle invalid input exceptions
*/

t_bool		is_handlable(t_options *opts, char *tipep)
{
	if (opts->type != UNKNOWN)
		return (TRUE);
	else
		invalid_algo(tipep);
	return (FALSE);
}

/*
** @info: Do I need to explain ?
*/

void		usage(void)
{
	ft_fprintf(2, "usage: ./ft_ssl [ md5 | sha224 | sha256 ] [-pqrs]\n");
	exit(1);
}

int			fferror(const char *msg, const char *file)
{
	ft_fprintf(2, "ft_ssl: %s: %s\n", file, msg);
	return (-1);
}
