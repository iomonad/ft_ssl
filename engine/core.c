/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:04:46 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/03 13:41:42 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

int	main(int argc, char *argv[])
{
	ft_printf("%d - %s\n", argc, argv[0]);
	return (EXIT_SUCCESS);
}
