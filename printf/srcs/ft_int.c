/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:17:22 by macbook           #+#    #+#             */
/*   Updated: 2021/11/05 00:56:23 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void    ft_int(t_print  *tab, char c)
{
    int i;
    int j;
    char    *nbr;

    i = 0;
    j = va_arg(tab->args,int);
	if (c == 'u')
		nbr = ft_unsigneditoa((unsigned int)j);
	else
    	nbr = ft_itoa(j);
    if (!nbr)
        return ;
	while (tab->wdt-- > ft_strlen(nbr) && tab->dash == 0)
    	tab->tl += write(1, " ", 1);
    while (nbr[i])
        tab->tl += write(1, &nbr[i++], 1);
	while (tab->wdt-- > ft_strlen(nbr) && tab->dash == 1)
        tab->tl += write(1, " ", 1);
    free (nbr);

}

int	ft_format(t_print *tab, const char *format, int pos)
{
	if ((format[pos]) == '-')
	{
		pos++;
    	tab->dash = 1;
	}
	while (ft_isdigit(format[pos]))
  {
    tab->wdt = tab->wdt * 10 + (format[pos] - '0');
    pos++;
  }
    if (format[pos] == 'd' || format[pos] == 'i' || format[pos] == 'u')
        ft_int(tab, format[pos]);
    if (format[pos] == 'c' || format[pos] == '%')
        ft_char(tab, format[pos]);
     if (format[pos] == 's')
        ft_string(tab);
      if (format[pos] == 'p')
        ft_pointer(tab);
     if (format[pos] == 'x' || format[pos] == 'X')
        ft_hex(tab, format[pos]);
    return (pos);
}