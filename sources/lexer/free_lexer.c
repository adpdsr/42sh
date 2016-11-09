/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 23:14:28 by gwells            #+#    #+#             */
/*   Updated: 2016/07/31 23:15:21 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>
#include "lineedit.h"

void			free_lexer_list(t_lexer **head)
{
	t_lexer	*next;

	while (*head)
	{
		next = (*head)->next;
		free((*head)->content);
		ft_freetab((*head)->cmd);
		free(*head);
		*head = next;
	}
}
