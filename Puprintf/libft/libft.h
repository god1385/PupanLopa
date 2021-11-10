/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:22:36 by ctorrek           #+#    #+#             */
/*   Updated: 2021/10/15 19:43:25 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isdigit(int nb);
char	*ft_itoa(int n);
int		ft_strlen(const char *str);
int		ft_putnbr_base(unsigned long n, char *base);
char	*ft_strdup(char *s);

#endif
