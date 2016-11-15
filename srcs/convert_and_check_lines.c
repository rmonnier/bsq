/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_checks_lines.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:46:01 by rmonnier          #+#    #+#             */
/*   Updated: 2016/09/22 12:04:46 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		convert_and_checks(char *param, int *tab, char *buf, int nb_col)
{
	int		i;

	i = 0;
	while (i < nb_col)
	{
		if (buf[i] == param[0])
			tab[i] = 1;
		else if (buf[i] == param[1])
			tab[i] = 0;
		else
			return (0);
		i++;
	}
	if (buf[i] != '\n')
		return (0);
	return (1);
}

int		get_first_line(int *tab, int fd, int nb_col, char *param)
{
	char	*buf;

	if ((buf = (char*)malloc(sizeof(char) * (nb_col + 1))) == 0)
		exit(0);
	if (read(fd, buf, nb_col + 1) == 0)
		return (0);
	if (convert_and_checks(param, tab, buf, nb_col) == 0)
		return (0);
	free(buf);
	return (1);
}

int		get_next_line(int *tab, int fd, int nb_col, char *param)
{
	char	*buf;
	int		i;

	if ((buf = (char*)malloc(sizeof(char) * (nb_col + 1))) == 0)
		exit(0);
	i = -1;
	while (++i < nb_col)
		tab[i + nb_col] = tab[i];
	if (read(fd, buf, nb_col + 1) == 0)
		return (0);
	if (convert_and_checks(param, tab, buf, nb_col) == 0)
		return (0);
	free(buf);
	return (1);
}
