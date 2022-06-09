/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 05:01:26 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/06/09 16:51:02 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_check_flag(va_list list, const char ltr);
int		ft_char(char c);
char	ft_str(char *str);
int		ft_strlen(const char *str);
int		ft_unsig_base(unsigned long int unsig_nbr, char	*base);
int		ft_nbr(int nb);

#endif