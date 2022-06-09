/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:39:46 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/06/09 08:04:50 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_check_flag(va_list format, char ltr)
{
	int	len;

	len = 0;
	if (ltr == 'c')
		return (ft_putchar(va_arg(format, int)));
	if (ltr == 's')
		return (ft_putstr(va_arg(format, char *)));
	if (ltr == 'p')
		return (write(1, "0x", 2)
			+ ft_put_unsig_nbr_base(va_arg(format, unsigned long int),
				"0123456789abcdef"));
	if (ltr == 'd' || ltr == 'i')
		return ();
	return (ft_putchar(ltr));
}

int	ft_printf(const char *str, ...)
{
	va_list	format;
	int		i;
	int		len;

	va_start (format, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_check_flag(format, str[++i]);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(format);
	return (len);
}

int	main(void)
{
	ft_printf("%p", );
}
