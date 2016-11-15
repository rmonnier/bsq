/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_is_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:58:55 by rmonnier          #+#    #+#             */
/*   Updated: 2016/09/21 17:43:51 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		putintab(int tab[3], int i, int j, int k)
{
	tab[0] = i;
	tab[1] = j;
	tab[2] = k;
	return (1);
}

int		max_is_one(char *av, int size[3], char param[4], int max[3])
{
	int		fd;
	char	*buf;
	int		i;
	int		j;

	fd = initialize_read(av, size);
	if ((buf = (char*)malloc(sizeof(char) * (size[2] + 1))) == 0)
		exit(0);
	read(fd, buf, size[2] + 1);
	j = -1;
	while (++j < size[2])
	{
		if (buf[j] == param[0])
			return (putintab(max, 1, 0, j));
	}
	i = 0;
	while (++i <= max[1])
	{
		read(fd, buf, size[2] + 1);
		if (buf[0] == param[0])
			return (putintab(max, 1, i, 0));
	}
	return (1);
}
