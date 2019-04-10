/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:58:16 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/10 13:19:52 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <engine.h>
#include <crypto.h>

int			process(t_options *opts, t_dlist *plist)
{
	t_input	*input;

	while (plist != NULL)
	{
		input = (t_input*)plist->content;
		pipeline(opts, input);
		plist = plist->next;
	}
	return (1);
}
