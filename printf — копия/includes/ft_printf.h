/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:02:26 by macbook           #+#    #+#             */
/*   Updated: 2021/11/01 23:35:32 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_print
{
	va_list	args;
	int		width;
	int		tall;
}	t_print;

t_print	*ft_initialise_tab(t_print *tab);
int		ft_printf(const char *format, ...);
void	ft_int(t_print *tab, char m);
void	ft_width(t_print *tab);
int		ft_format(t_print *tab, const char *format, int pos);
void	ft_char(t_print *tab, char m);
void	ft_string(t_print *tab);
void	ft_pointer(t_print *tab);
void	ft_hex(t_print *tab, char c);

#endif
