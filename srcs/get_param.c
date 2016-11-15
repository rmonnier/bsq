/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 00:40:21 by rmonnier          #+#    #+#             */
/*   Updated: 2016/09/21 19:47:00 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		sizeof_first_two_lines(int fd, int size[3])
{
	char	buf[1];
	int		j;

	j = read(fd, buf, 1);
	if (j == 0 || j == -1)
		return (0);
	j = 0;
	while (buf[0] != '\n')
	{
		if ((read(fd, buf, 1)) == 0)
			return (0);
		j++;
	}
	size[0] = j;
	if ((read(fd, buf, 1)) == 0)
		return (0);
	j = 0;
	while (buf[0] != '\n')
	{
		if ((read(fd, buf, 1)) == 0)
			return (0);
		j++;
	}
	size[2] = j;
	return (1);
}

int		three_different_char(char param[4])
{
	if (param[0] == param[1] || param[1] == param[2] ||
		param[0] == param[2])
		return (0);
	return (1);
}

int		only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		get_param(char *file_name, char param[4], int size[3])
{
	char	*buf;
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	if (sizeof_first_two_lines(fd, size) == 0)
		return (0);
	close(fd);
	if (size[0] < 4)
		return (0);
	if ((buf = (char*)malloc(sizeof(char) * size[0])) == 0)
		exit(0);
	fd = open(file_name, O_RDONLY);
	read(fd, buf, size[0]);
	param[0] = buf[size[0] - 3];
	param[1] = buf[size[0] - 2];
	param[2] = buf[size[0] - 1];
	param[3] = '\0';
	buf[size[0] - 3] = '\0';
	if ((only_digits(buf) && three_different_char(param)) == 0)
		return (0);
	size[1] = ft_atoi(buf);
	close(fd);
	free(buf);
	return (1);
}
