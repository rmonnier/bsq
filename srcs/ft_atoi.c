/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:07:52 by rmonnier          #+#    #+#             */
/*   Updated: 2016/09/20 16:50:54 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		white_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == ' ');
}

int		ft_atoi(char *str)
{
	int nb;
	int i;
	int neg;

	nb = 0;
	neg = 1;
	i = 0;
	while (white_space(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	nb = nb * neg;
	return (nb);
}
