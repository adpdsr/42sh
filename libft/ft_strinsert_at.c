/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:10:40 by gwells            #+#    #+#             */
/*   Updated: 2016/07/24 10:51:32 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strinsert_at(char *str, char c, size_t pos)
{
	char	*ret;

	ret = ft_memalloc_fail(sizeof(char) * ft_strlen(str) + 2);
	ft_strncpy(ret, str, pos);
	ret[pos] = c;
	ft_strcpy(&ret[pos + 1], &str[pos]);
	return (ret);
}
