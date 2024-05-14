/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:11:37 by aidgomez          #+#    #+#             */
/*   Updated: 2023/02/15 14:11:37 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long long n, int base)
{
	unsigned long long	i;

	i = 0;
	if (n >= 16)
	i += ft_printhex(n / 16, base);
	if (base == 0)
		ft_printchar(HEX_LOWERCASE[n % 16]);
	else
		ft_printchar(HEX_UPPERCASE[n % 16]);
	i++;
	return (i);
}
