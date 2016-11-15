/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:59:25 by rmonnier          #+#    #+#             */
/*   Updated: 2016/09/22 11:37:54 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		resolve_bsq(char *file_name)
{
	char	param[4];
	int		max[3];
	int		size[3];

	max[0] = 0;
	max[1] = 0;
	max[2] = 0;
	if (get_param(file_name, param, size) == 0)
		return (0);
	if (bsq(file_name, size, param, max) == 0)
		return (0);
	if (max[0] == 1 || max[0] == 0)
		max_is_one(file_name, size, param, max);
	print_bsq(file_name, size, param, max);
	return (1);
}

void	create_file(void)
{
	int		fd;
	int		i;
	char	buf[1];

	i = 0;
	fd = open("stdin.txt", O_CREAT | O_WRONLY | O_TRUNC);
	while (read(0, buf, 1))
	{
		write(fd, buf, 1);
		i++;
	}
	close(fd);
}

int		main(int ac, char **av)
{
	int i;

	if (ac == 1)
	{
		create_file();
		if (resolve_bsq("stdin.txt") == 0)
			write(2, "map error\n", 10);
	}
	i = 1;
	while (i < ac)
	{
		if (resolve_bsq(av[i]) == 0)
			write(2, "map error\n", 10);
		if (i != ac - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
