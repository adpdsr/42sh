/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsupress_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:45:09 by gwells            #+#    #+#             */
/*   Updated: 2016/07/24 10:46:11 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsupress_at(char *str, size_t pos)
{
	char	*ret;
	char	*tmp;

	tmp = ft_memalloc_fail(sizeof(char) * ft_strlen(str));
	tmp = ft_strncpy(tmp, str, pos);
	pos++;
	while (*str && pos--)
		str++;
	ret = ft_strjoin(tmp, str);
	free(tmp);
	return (ret);
}
