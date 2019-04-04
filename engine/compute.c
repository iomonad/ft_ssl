/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:58:16 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/04 14:42:38 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <engine.h>

int			process(t_options *opts, t_dlist *plist)
{
	t_input	*input;

	ft_printf("Waiting for hash algorithm implementation\n");
	ft_printf("p = %d\nq = %d\nr = %d\n\n",
		opts->p, opts->q, opts->r);
	while (plist != NULL)
	{
		input = (t_input*)plist->content;
		ft_printf("Entities to process: %s - Method: %d\n",
			input->input, input->method);
		plist = plist->next;
	}
	return (1);
}
