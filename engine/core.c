/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:04:46 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/03 16:23:03 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>
#include <libft.h>

static t_hash	hashtype(char *type)
{
	if (type != NULL)
	{
		if (ft_strequ(type, TMD5))
			return (MD5);
		else if (ft_strequ(type, TSHA256))
			return (SHA256);
		else
			return (UNKNOWN);
	}
	return (UNKNOWN);
}

/*
** @info Parse options
*/

static void		parseopts(t_options *opts, int argc, char **argv)
{
	int			c;

	opts->p = FALSE;
	opts->q = FALSE;
	opts->r = FALSE;
	opts->string = NULL;
	opts->type = hashtype(argv[1]);
	while ((c = ft_getopt(argc - 1, &argv[1], "pqrs:")) != -1)
	{
		if (c == 'p')
			opts->p = TRUE;
		else if (c == 'q')
			opts->q = TRUE;
		else if (c == 'r')
			opts->r = TRUE;
		else if (c == 's')
			opts->string = ft_strdup(g_optarg);
		else
			usage();
	}
}

int				main(int argc, char *argv[])
{
	t_options	opts;
	t_list		*plist;

	plist = NULL;
	if (argc <= 1)
		usage();
	parseopts(&opts, argc, argv);
	if (is_handlable(&opts, plist, argv[1]))
		return (process(&opts, plist));
	return (0);
}
