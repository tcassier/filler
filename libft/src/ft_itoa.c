/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:28:06 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/05 00:31:02 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		length;
	int		sign;
	char	*str;

	length = ft_nbrlen_base(n, 10);
	sign = n < 0 ? -1 : 1;
	if (!(str = ft_strnew(length)))
		return (NULL);
	while (length--)
	{
		str[length] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
