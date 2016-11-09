/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 20:40:35 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/08 20:47:59 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lineedit.h>

char	*line_edit1(int sub, char *buffer)
{
	if (!sub)
		signal(SIGINT, sig_clear);
	else
		signal(SIGINT, SIG_IGN);
	ft_memset(buffer, '\0', 7);
	read(0, buffer, 7);
	return (buffer);
}
