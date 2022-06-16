/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:08:39 by nolaso-u          #+#    #+#             */
/*   Updated: 2022/06/16 13:36:04 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *str)
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

int	ft_unsig_base(unsigned long int unsig_nbr, char	*base)
{
	unsigned long int	baselen;
	int					i;

	i = 0;
	baselen = ft_strlen(base);
	if (unsig_nbr >= baselen)
		i += ft_unsig_base(unsig_nbr / baselen, base);
	i += ft_char(base[unsig_nbr % baselen]);
	return (i);
}

int	ft_nbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (nb < 0)
		{
			i += ft_char('-');
			nb = nb * (-1);
		}
		if (nb > 9)
		{
			i += ft_nbr(nb / 10);
			i += ft_char(nb % 10 + '0');
		}
		else
			i += ft_char(nb + '0');
	}
	return (i);
}
