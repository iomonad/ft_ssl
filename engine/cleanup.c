/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:27:49 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/15 09:55:56 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>
#include <stdlib.h>

/*
** Compatibility clean wrapper
*/

static void		clean_input(t_input *input)
{
	if (input->input != NULL)
		free(input->input);
}

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

static void		clean_list(t_dlist *dlist)
{
	t_dlist		*head;
	t_dlist		*cur;

	head = dlist;
	while (head != NULL)
	{
		cur = head;
		head = head->next;
		free(cur->content);
		free(cur);
	}
}

uint_fast32_t	clean_runtime(t_input *input,
					t_options *opts,
					t_dlist *dlist)
{
	clean_input(input);
	clean_options(opts);
	clean_list(dlist);
	return (0);
}
