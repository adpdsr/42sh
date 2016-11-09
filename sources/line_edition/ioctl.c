/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioctl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:47:53 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 15:02:39 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

#ifdef __APPLE__

static char		*parse_slot(int slot)
{
	char		*ret;
	char		*slot_c;
	size_t		len;

	slot_c = ft_itoa(slot);
	len = ft_strlen(slot_c);
	if (len == 1)
		ret = ft_strjoin("00", slot_c);
	else if (len == 2)
		ret = ft_strjoin("0", slot_c);
	else
		ret = ft_strdup(slot_c);
	free(slot_c);
	return (ret);
}

static int		get_slot(void)
{
	int			slot;
	int			maj;
	struct stat s_stat;

	slot = ttyslot();
	if (fstat(0, &s_stat) == -1)
		ft_quit("Stat can't reach stdin", 2, -1);
	maj = major(s_stat.st_rdev);
	maj *= 10;
	slot -= maj;
	slot -= 4;
	return (slot);
}

int				fd_ioctl(void)
{
	int			fd;
	char		*file;
	char		*slot;

	slot = parse_slot(get_slot());
	file = ft_strjoin("/dev/ttys", slot);
	ft_strdel(&slot);
	fd = ft_open_file(file, 0);
	free(file);
	return (fd);
}

#elif __linux__

int				fd_ioctl(void)
{
	int			fd;

	fd = ft_open_file("/dev/pts/2", 0);
	return (fd);
}

#else

int				fd_ioctl(void)
{
	ft_putendl_fd("OS not supported", 2);
	exit(0);
}
#endif
