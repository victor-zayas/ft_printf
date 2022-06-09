/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:08:39 by nolaso-u          #+#    #+#             */
/*   Updated: 2022/06/09 07:59:33 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

char	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	else
		while (str[i])
			(write(1, &str[i++], 1));
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_put_unsig_nbr_base(unsigned long int unsig_nbr, char	*base)
{
	unsigned long int	baselen;
	int					i;

	i = 0;
	baselen = ft_strlen(base);
	if (unsig_nbr >= baselen)
		i += ft_put_unsig_nbr_base(unsig_nbr / baselen, base);
	i += ft_putchar(base[unsig_nbr % baselen]);
	return (i);
}
