/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:03:32 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/14 10:27:16 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	spread_and_save_max(int *tab, int i, int nb_col, int max[3])
{
	int j;

	j = 1;
	while (j < nb_col)
	{
		if (tab[j] != 0)
			tab[j] = 1 + min(tab[j - 1], tab[j + nb_col - 1], tab[j + nb_col]);
		if (tab[j] > max[0])
		{
			max[0] = tab[j];
			max[1] = i;
			max[2] = j;
		}
		j++;
	}
}

int		open_and_skip_param(char *av, int *fd, int size[3])
{
	char	*buf;

	if ((buf = (char*)malloc(sizeof(char) * (size[0] + 1))) == 0)
		exit(0);
	*fd = open(av, O_RDONLY);
	if (read(*fd, buf, size[0] + 1) == 0)
		return (0);
	free(buf);
	return (1);
}

int		close_and_check_end(int fd)
{
	char buf[1];

	if (read(fd, buf, 1) != 0)
		return (0);
	close(fd);
	return (1);
}

int		bsq(char *av, int size[3], char param[4], int max[3])
{
	int		*tab;
	int		i;
	int		fd;

	if (open_and_skip_param(av, &fd, size) == 0)
		return (0);
	if ((tab = (int*)malloc(sizeof(int) * (2 * size[2]))) == 0)
		exit(0);
	if (get_first_line(tab, fd, size[2], param) == 0)
		return (0);
	i = 0;
	while (++i < size[1])
	{
		if (get_next_line(tab, fd, size[2], param) == 0)
			return (0);
		spread_and_save_max(tab, i, size[2], max);
	}
	if (close_and_check_end(fd) == 0)
		return (0);
	free(tab);
	return (1);
}
