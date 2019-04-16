/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:27:49 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/16 11:45:47 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>
#include <stdlib.h>

/*
** Compatibility clean wrapper
*/

static void		clean_options(t_options *opts)
{
	return ((void)opts);
}

/*
** Compatibility clean wrapper
*/

static void		clean_list(t_dlist **dlist)
{
	t_dlist		*node;
	t_dlist		*tmp;

	node = *dlist;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp->content);
		free(tmp);
	}
	dlist = NULL;
}

uint_fast32_t	clean_runtime(t_options *opts,
					t_dlist **dlist)
{
	clean_options(opts);
	clean_list(dlist);
	return (0);
}
