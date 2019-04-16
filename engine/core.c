/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:04:46 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/16 11:43:26 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>
#include <libft.h>
#include <stdlib.h>

/*
** @info Program entrypoint
*/

int				main(int argc, char *argv[])
{
	t_options	opts;
	t_dlist		*plist;

	plist = NULL;
	if (argc <= 1)
		usage();
	parseopts(&opts, argc, argv, &plist);
	parseinput(argc, argv, &plist);
	if (plist == NULL)
		memoize(STDIN, NULL, &plist);
	if (is_handlable(&opts, argv[1]))
		process(&opts, plist);
	return (clean_runtime(&opts, &plist));
}
