/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:54:01 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/04 14:51:05 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <engine.h>

t_hash		hashtype(char *type)
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

void		memoize(t_meth method, char *entities, t_dlist **head)
{
	t_input	input;

	ft_bzero(&input, sizeof(input));
	if (entities != NULL)
		input.input = ft_strdup(entities);
	input.method = method;
	ft_dlstappend(head, ft_dlstnew(&input, sizeof(input)));
}

/*
** @info Parse options
*/

void		parseopts(t_options *opts, int argc, char **argv, t_dlist **head)
{
	int		c;

	opts->p = FALSE;
	opts->q = FALSE;
	opts->r = FALSE;
	opts->type = hashtype(argv[1]);
	while ((c = ft_getopt(argc - 1, &argv[1], "pqrs:")) != -1)
	{
		if (c == 'p')
		{
			opts->p = TRUE;
			memoize(STDIN, NULL, head);
		}
		else if (c == 'q')
			opts->q = TRUE;
		else if (c == 'r')
			opts->r = TRUE;
		else if (c == 's')
			memoize(STRING, g_optarg, head);
		else
			usage();
	}
}

void		parseinput(int argc, char *argv[], t_dlist **head)
{
	g_optind++;
	while (g_optind < argc)
		memoize(FARG, argv[g_optind++], head);
}
