/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:17:22 by ctorrek           #+#    #+#             */
/*   Updated: 2021/11/01 23:38:37 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->width = 0;
	tab->tall = 0;
	return (tab);
}

int	ft_format(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'd' || format[pos] == 'i' || format[pos] == 'u')
		ft_int(tab, format[pos]);
	if (format[pos] == 'c' || format[pos] == '%')
		ft_char(tab, format[pos]);
	if (format[pos] == 'x' || format[pos] == 'X')
		ft_hex(tab, format[pos]);
	if (format[pos] == 's')
		ft_string(tab);
	if (format[pos] == 'p')
		ft_pointer(tab);
	return (pos);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = -1;
	count = 0;
	if (!format[0])
		return (0);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_format(tab, format, i + 1);
		else
			count += write(1, &format[i], 1);
	}
	count += tab->tall;
	va_end(tab->args);
	free (tab);
	return (count);
}

