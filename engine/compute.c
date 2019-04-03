/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:58:16 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/03 16:16:00 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <engine.h>

int	process(t_options *opts, t_list *plist)
{
	(void)plist;
	ft_printf("Waiting for hash algorithm implementation\n");
	ft_printf("p = %d\nq = %d\nr = %d\ns = %s\n", opts->p, opts->q, opts->r, opts->string);
	return (1);
}
