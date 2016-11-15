/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:38:43 by rmonnier          #+#    #+#             */
/*   Updated: 2016/09/21 17:43:21 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

int		initialize_read(char *av, int size[3]);
int		max_is_one(char *av, int size[3], char param[4], int max[3]);
int		get_first_line(int *tab, int fd, int nb_col, char *param);
int		get_next_line(int *tab, int fd, int nb_col, char *param);
int		min(int i, int j, int k);
void	print_bsq(char *av, int size[3], char param[4], int max[3]);
int		ft_atoi(char *str);
int		get_param(char *file_name, char param[4], int size[3]);
int		bsq(char *av, int size[3], char param[4], int max[3]);

#endif
