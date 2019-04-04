/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:58:16 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/04 16:21:21 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <engine.h>
#include <crypto.h>

static void	dispatch(t_options *opts, t_input *input)
{
	ft_printf("Processing: %s - Method: %d\n",
		input->input, input->method);

	for (int i = 0; g_interface[i].type != SENTINEL; i++) {
		if (g_interface[i].type == opts->type) {
			if ((*g_interface[i].hashf) == NULL) {
				ft_printf("Processing un-implemented algorithm.\n");
			} else {
				(*g_interface[i].hashf)(input->input);
			}
		}
	}
}

int			process(t_options *opts, t_dlist *plist)
{
	t_input	*input;

	while (plist != NULL)
	{
		input = (t_input*)plist->content;
		dispatch(opts, input);
		plist = plist->next;
	}
	return (1);
}
