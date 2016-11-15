/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:54:28 by rmonnier          #+#    #+#             */
/*   Updated: 2016/09/21 17:32:49 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		min(int i, int j, int k)
{
	if (i <= j)
		return (i <= k ? i : k);
	else
		return (j <= k ? j : k);
}

int		initialize_read(char *av, int size[3])
{
	char	*buf;
	int		fd;

	fd = open(av, O_RDONLY);
	if ((buf = (char*)malloc(sizeof(char) * (size[0] + 1))) == 0)
		exit(0);
	read(fd, buf, size[0] + 1);
	free(buf);
	return (fd);
}

void	print_bsq(char *av, int size[3], char param[4], int max[3])
{
	char	*buf;
	int		i;
	int		j;
	int		fd;

	fd = initialize_read(av, size);
	if ((buf = (char*)malloc(sizeof(char) * (size[2] + 1))) == 0)
		exit(0);
	i = -1;
	while (++i < size[1])
	{
		read(fd, buf, size[2] + 1);
		j = -1;
		while (++j < size[2] + 1)
		{
			if (i < max[1] - max[0] + 1 || i > max[1])
				write(1, buf, (j = size[2] + 1));
			else if (j >= max[2] - max[0] + 1 && j <= max[2])
				write(1, &(param[2]), 1);
			else
				write(1, &(buf[j]), 1);
		}
	}
	free(buf);
	close(fd);
}
